<?php

namespace PAXB\Xml\Marshall;

use PAXB\Xml\Binding\Metadata\Metadata;
use PAXB\Xml\Binding\Metadata\MetadataFactoryInterface;
use PAXB\Xml\Binding\Structure\Attribute;
use PAXB\Xml\Binding\Structure\Base;
use PAXB\Xml\Binding\Structure\Element;

class DOMDocumentMarshaller implements MarshallerInterface
{
    /**
     * @var \PAXB\Xml\Binding\Metadata\MetadataFactoryInterface
     */
    private $metadataFactory;

    /**
     * @param \PAXB\Xml\Binding\Metadata\MetadataFactory $metadataFactory
     */
    public function __construct(MetadataFactoryInterface $metadataFactory)
    {
        $this->metadataFactory = $metadataFactory;
    }

    /**
     * @param mixed $object
     * @param bool $format
     * @return string
     */
    public function marshall($object, $format = false)
    {
        $domDocument = new \DOMDocument();
        $domDocument->formatOutput = $format;
        $domDocument->preserveWhiteSpace = $format;

        return $this->marshallObject($domDocument, $object)->saveXML();
    }

    /**
     * @param \DOMDocument $document
     * @param mixed $object
     * @param \DOMElement $parent
     * @param string $parentLevelName
     * @return \DOMDocument
     * @throws Exception
     */
    private function marshallObject(\DOMDocument $document, $object, $parent = null, $parentLevelName = null)
    {
        if (!is_object($object)) {
            throw new Exception('Cannot marshall primitive types or arrays');
        }

        $metadata = $this->metadataFactory->getClassMetadata(get_class($object));
#d(__METHOD__, $metadata);

        $rootElementName = is_null($parentLevelName) ? $metadata->getName() : $parentLevelName;
#d(__METHOD__, $rootElementName);

        $element  = $document->createElement($rootElementName);
#d(__METHOD__, __LINE__, $element);

        $this->processAttributes($object, $metadata, $element);
 #d(__METHOD__, __LINE__, $element);

        $this->processSubElements($document, $object, $metadata, $element);
 d(__METHOD__, __LINE__, $element);

        $this->processValueElement($document, $object, $metadata, $element);

        if ($parent == null) {
            $document->appendChild($element);
        } else {
            $parent->appendChild($element);
        }

        return $document;
    }

    /**
     * @param mixed $object
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @param \DOMElement $element
     * @throws Exception
     */
    private function processAttributes($object, $metadata, $element)
    {
        /** @var Attribute $attributeMetadata */
        foreach ($metadata->getAttributes() as $propertyName => $attributeMetadata) {
            $attributeValue = $this->getPropertyValue(
                $metadata->getReflection()->getProperty($propertyName),
                $attributeMetadata,
                $object
            );

            if (!is_scalar($attributeValue)) {
                throw new Exception(
                    'Cannot marshall field ' . $attributeMetadata->getName() . ' as attribute, value is not scalar'
                );
            }
#d(__METHOD__, __LINE__, $attributeValue);

            $element->setAttribute($attributeMetadata->getName(), $attributeValue);
        }
    }

    /**
     * @param \DOMDocument $document
     * @param mixed $object
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @param \DOMNode $element
     */
    private function processSubElements(\DOMDocument $document, $object, $metadata, $element)
    {
        /** @var Element $elementMetadata */
        foreach ($metadata->getElements() as $propertyName => $elementMetadata) {
            $elementValue = $this->getPropertyValue(
                $metadata->getReflection()->getProperty($propertyName),
                $elementMetadata,
                $object
            );
d(__METHOD__, __LINE__, $elementValue);

            $this->checkTypeHinting($elementMetadata, $elementValue);
            $this->createAndAppendChild($document, $elementValue, $elementMetadata, $element);
        }
    }

    /**
     * @param \DOMDocument $document
     * @param mixed $object
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @param \DOMElement $element
     * @throws Exception
     */
    private function processValueElement(\DOMDocument $document, $object, $metadata, $element)
    {
        $valueElement = $metadata->getValueElement();
        if (!empty($valueElement)) {
            $property = $metadata->getReflection()->getProperty($valueElement);
            $property->setAccessible(true);
            $value = $property->getValue($object);

            if (!is_scalar($value)) {
                throw new Exception(
                    'Cannot marshall field ' . $metadata->getValueElement() . ' as text node is not scalar'
                );
            }
            $textNode = $document->createTextNode($value);
            $element->appendChild($textNode);
        }
    }

    /**
     * @param \ReflectionProperty $property
     * @param Base $baseMetadata
     * @param mixed $object
     * @return mixed
     */
    private function getPropertyValue(\ReflectionProperty $property, Base $baseMetadata, $object)
    {
        if ($baseMetadata->getSource() == Base::FIELD_SOURCE) {
            $property->setAccessible(true);

            return $property->getValue($object);
        } else {
            return $object->{'get'.ucfirst($property->getName())}();
        }
    }

    /**
     * @param Element $elementMetadata
     * @param mixed $elementValue
     * @throws Exception
     */
    private function checkTypeHinting(Element $elementMetadata, $elementValue)
    {
        if ($this->isTraversable($elementValue)) {
            $nestedValue = null;
            foreach ($elementValue as $nestedValue) {
                break;
            }
            $elementValue = $nestedValue;

        }
        if ($elementMetadata->getType() == Metadata::DEFINED_TYPE && !empty($elementValue)) {
            if (!is_object($elementValue) || get_class($elementValue) !== $elementMetadata->getTypeValue()) {
                throw new Exception(
                    'Cannot marshall field ' . $elementMetadata->getName(
                    ) . ' as type ' . $elementMetadata->getTypeValue(). ' founded type is: '.get_class($elementValue)
                );
            }
        }
    }

    /**
     * @param \DOMDocument $document
     * @param mixed $elementValue
     * @param Element $elementMetadata
     * @param \DOMElement $element
     */
    private function createAndAppendChild(\DOMDocument $document, $elementValue, $elementMetadata, $element)
    {
        $baseElement = $element;
        $elementWrapper = $elementMetadata->getWrapperName();
        if (!empty($elementWrapper)) {
            $nestedElement = $document->createElement($elementWrapper);
            $element->appendChild($nestedElement);
            $baseElement = $nestedElement;
        }

        if ($this->isTraversable($elementValue)) {
            foreach ($elementValue as $singleElementValue) {
                $this->createSubElement($document, $singleElementValue, $elementMetadata, $baseElement);
            }
        } else {
            $this->createSubElement($document, $elementValue, $elementMetadata, $baseElement);
        }
    }

    /**
     * @param \DOMDocument $document
     * @param mixed $elementValue
     * @param Element $elementMetadata
     * @param \DOMElement $element
     */
    private function createSubElement(\DOMDocument $document, $elementValue, $elementMetadata, $element)
    {
        if (is_object($elementValue)) {
            $this->marshallObject($document, $elementValue, $element, $elementMetadata->getName());
        } else {
            if ($elementMetadata->getType() == Metadata::RUNTIME_TYPE) {
                $nestedElement = $document->createElement($elementMetadata->getName());
                $textElement   = $document->createTextNode($elementValue);
                $nestedElement->appendChild($textElement);
                $element->appendChild($nestedElement);
            }
        }
    }

    /**
     * @param mixed $elementValue
     * @return bool
     */
    private function isTraversable($elementValue)
    {
        return is_array($elementValue)
            || $elementValue instanceof \Iterator
            || $elementValue instanceof \IteratorAggregate;
    }
}
