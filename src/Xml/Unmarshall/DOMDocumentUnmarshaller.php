<?php

namespace PAXB\Xml\Unmarshall;

use DOMDocument;
use DOMElement;
use ReflectionProperty;
use PAXB\Binding\Structure\AbstractStructure;
use PAXB\Binding\Structure\StructureInterface;
use PAXB\Binding\Metadata\Metadata;
use PAXB\Binding\Metadata\FactoryInterface;
use PAXB\Xml\Binding\Structure\Attribute;
use PAXB\Xml\Binding\Structure\Element;

class DOMDocumentUnmarshaller implements UnmarshallerInterface
{
    /**
     * @var \PAXB\Binding\Metadata\FactoryInterface
     */
    private $metadataFactory;

    /**
     * @param \PAXB\Binding\Metadata\FactoryInterface $metadataFactory
     */
    public function __construct(FactoryInterface $metadataFactory)    {
        $this->metadataFactory = $metadataFactory;
    }

    /**
     * @param string $string
     * @param string $rootClass
     * @return mixed
     */
    public function unmarshall($string, $rootClass)
    {
        $document = new DOMDocument();
        $document->loadXML($string);
#d(__METHOD__, __LINE__, $this->metadataFactory);

        #$metadata = $this->metadataFactory->getMetadata($rootClass);
        $metadata = $this->metadataFactory->getMetadata($rootClass);
#d(__METHOD__, __LINE__, $metadata);
        $rootElementName = $metadata->getName();

        if ($document->childNodes->item(0)->nodeName !== $rootElementName) {
            throw new Exception('Cannot found root element: '.$rootElementName);
        }

        return $this->unmarshallObject($document->childNodes->item(0), $this->getNewEntity($metadata), $metadata);
    }

    /**
     * @param \PAXB\Binding\Metadata\Metadata $metadata
     * @return object
     */
    public function getNewEntity(Metadata $metadata)
    {
        $className = $metadata->getClassName();
        $object = new $className();
        return $object;
    }

    /**
     * @param \DOMElement $node
     * @param mixed $object
     * @param \PAXB\Binding\Metadata\Metadata $metadata
     */
    private function unmarshallObject(DOMElement $node, $object, Metadata $metadata)
    {
        $this->processAttributes($node, $object, $metadata);
        $this->processElements($node, $metadata, $object);
        $this->processValue($node, $object, $metadata);

        return $object;
    }

    /**
     * @param \DOMElement $node
     * @param mixed $object
     * @param \PAXB\Binding\Metadata\Metadata $metadata
     * @throws Exception
     */
    private function processAttributes(DOMElement $node, $object, Metadata $metadata)
    {
        /** @var Attribute $attribute */
        foreach ($metadata->getAttributes() as $fieldName => $attribute) {
            if (!$node->hasAttribute($attribute->getName())) {
                throw new Exception('Cannot found attribute ' . $attribute->getName(
                ) . ' of node ' . $metadata->getName());
            }

            $this->setPropertyValue(
                $metadata->getReflectionClass()->getProperty($fieldName),
                $attribute,
                $object,
                $node->getAttribute($attribute->getName())
            );
        }
    }

    /**
     * @param \DOMElement $node
     * @param \PAXB\Binding\Metadata\Metadata $metadata
     * @param mixed $object
     * @throws Exception
     */
    private function processElements(DOMElement $node, Metadata $metadata, $object)
    {
        /** @var Element $element */
        foreach ($metadata->getElements() as $fieldName => $element) {

echo __METHOD__ . ':' . __LINE__ . ": fieldName: $fieldName\n";

            $childNodes = [];
            $wrapperName = $element->getWrapperName();

echo __METHOD__ . ':' . __LINE__ . ": wrapperName: $wrapperName\n";

            if (!empty($wrapperName)) {
                if ($this->hasChild($node, $wrapperName)) {
                    $wrappers = $this->filterChildNodes($node, $wrapperName);
                    if (count($wrappers) > 1) {
                        throw new Exception('Found not unique wprappers ' . $wrapperName . ' inside ' . $node->nodeName);
                    }

                    $childNodes = $this->filterChildNodes($wrappers[0], $element->getName());
                }
            } else {
                $childNodes = $this->filterChildNodes($node, $element->getName());
echo __METHOD__ . ':' . __LINE__ . ": filterChildNodes\n";
#print_r($childNodes);
            }

            $this->attachChildNodesToObject($object, $metadata, $childNodes, $element, $fieldName);
        }
    }

    /**
     * @param \DOMElement $node
     * @param mixed $object
     * @param \PAXB\Binding\Metadata\Metadata $metadata
     */
    private function processValue(DOMElement $node, $object, Metadata $metadata)
    {
        $valueElement = $metadata->getValueElement();
        if (!empty($valueElement)) {
            $fieldValue = '';
            foreach ($node->childNodes as $childNode) {
                if ($childNode instanceof \DOMText) {
                    $fieldValue .= $childNode->textContent;
                }
            }

            $property = $metadata->getReflectionClass()->getProperty($valueElement);
            $property->setAccessible(true);
            $property->setValue($object, $fieldValue);
        }
    }

    /**
     * @param \ReflectionProperty $property
     * @param \PAXB\Xml\Binding\Structure\StructureInterface $baseMetadata
     * @param mixed $object
     * @param mixed $value
     * @return mixed
     */
    private function setPropertyValue(ReflectionProperty $property, StructureInterface $baseMetadata, $object, $value)
    {
        if ($baseMetadata->getSource() == AbstractStructure::FIELD_SOURCE) {
            $property->setAccessible(true);
            $property->setValue($object, $value);
        } else {
echo __METHOD__ . ':' . __LINE__ . " - call setter\n";
            $object->{'set' . ucfirst($property->getName())}($value);
        }
    }

    /**
     * @param \DOMElement $node
     * @param string $childName
     * @return \DOMElement[]
     */
    private function filterChildNodes(DOMElement $node, $childName)
    {
        $result = [];
        if ($node->hasChildNodes()) {
            /** @var \DOMElement $childNode */
            foreach ($node->childNodes as $childNode) {
                if ($childNode->nodeName == $childName) {
                    $result[] = $childNode;
                }
            }
        }

        return $result;
    }

    /**
     * @param \DOMElement $node
     * @param string $childName
     * @return bool
     */
    private function hasChild(DOMElement $node, $childName)
    {
        if ($node->hasChildNodes()) {
            // \DOMElement $childNode
            foreach ($node->childNodes as $childNode) {
                if ($childNode->nodeName == $childName) {
                    return true;
                }
            }
        }

        return false;
    }

    /**
     * @param \PAXB\Xml\Binding\Structure\Element $element
     * @param \DOMElement $child
     * @return mixed
     * @throws Exception
     */
    private function getNodeElementValue(Element $element, DOMElement $child)
    {
        $fieldValue = null;
        if ($element->getType() === Metadata::RUNTIME_TYPE) {
            $fieldValue = $this->getScalarValueFromNode($element->getName(), $child);
        } else {
#echo "\n" . __METHOD__ . ':' . __LINE__ . ' - ' . $element->getTypeValue() . "\n\n";
#d($element);
            $childMetadata = $this->metadataFactory->getMetadata($element->getTypeValue());
 d(__METHOD__, $childMetadata);
            $fieldValue = $this->unmarshallObject(
                $child,
                $this->getNewEntity($childMetadata),
                $childMetadata
            );
        }

        return $fieldValue;
    }

    /**
     * @param mixed $object
     * @param \PAXB\Binding\Metadata\Metadata $metadata
     * @param \DOMElement[] $childNodes
     * @param \PAXB\Xml\Binding\Structure\Element $element
     * @param string $fieldName
     * @return mixed
     */
    private function attachChildNodesToObject(
        $object,
        Metadata $metadata,
        $childNodes,
        Element $element,
        $fieldName
    ) {
        if (count($childNodes) > 0) {

echo __METHOD__ . ':' . __LINE__ . ": childNodes > 0\n";

            if (count($childNodes) > 1 || $element->getPhpCollection()) {
                $fieldValue = [];
                foreach ($childNodes as $child) {
                    $fieldValue[] = $this->getNodeElementValue($element, $child);
                }
            } else {
                $fieldValue = null;
                $child = reset($childNodes);
                $fieldValue = $this->getNodeElementValue($element, $child);
            }

echo __METHOD__ . ':' . __LINE__ . ": fieldValue: $fieldValue\n";

            $this->setPropertyValue(
                $metadata->getReflectionClass()->getProperty($fieldName),
                $element,
                $object,
                $fieldValue
            );

            return $childNodes;
        }

        return $childNodes;
    }

    /**
     * @param string $elementName
     * @param \DOMElement $child
     * @return mixed
     * @throws Exception
     */
    private function getScalarValueFromNode($elementName, DOMElement $child)
    {
        if ($child->hasChildNodes()) {
            if (count($child->childNodes)>1 || !($child->childNodes->item(0) instanceof \DOMText)) {
                throw new Exception('Cannot unmarshal scalar ' . $elementName . ' as object');
            }
        }
        $fieldValue = $child->textContent;

        return $fieldValue;
    }
}
