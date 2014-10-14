<?php

namespace PAXB\Xml\Unmarshall;

use PAXB\Xml\Binding\Metadata\ClassMetadata;
use PAXB\Xml\Binding\Metadata\ClassMetadataFactory;
use PAXB\Xml\Binding\Structure\Attribute;
use PAXB\Xml\Binding\Structure\Base;
use PAXB\Xml\Binding\Structure\Element;

class DOMDocumentUnmarshaller implements UnmarshallerInterface
{
    /**
     * @var ClassMetadataFactory
     */
    private $classMetadataFactory;

    /**
     * @param ClassMetadataFactory $classMetadataFactory
     */
    public function __construct(ClassMetadataFactory $classMetadataFactory)
    {
        $this->classMetadataFactory = $classMetadataFactory;
    }

    /**
     * @param string $string
     * @param string $rootClass
     * @return mixed
     */
    public function unmarshall($string, $rootClass)
    {
        $document = new \DOMDocument();
        $document->loadXML($string);

        $classMetadata = $this->classMetadataFactory->getClassMetadata($rootClass);
        $rootElementName = $classMetadata->getName();

        if ($document->childNodes->item(0)->nodeName !== $rootElementName) {
            throw new Exception('Cannot found root element: '.$rootElementName);
        }

        return $this->unmarshallObject($document->childNodes->item(0), $this->getNewEntity($classMetadata), $classMetadata);
    }

    /**
     * @param \DOMElement $node
     * @param mixed $object
     * @param ClassMetadata $classMetadata
     */
    private function unmarshallObject(\DOMElement $node, $object, ClassMetadata $classMetadata)
    {
        $this->processAttributes($node, $object, $classMetadata);
        $this->processElements($node, $classMetadata, $object);
        $this->processValue($node, $object, $classMetadata);

        return $object;
    }

    /**
     * @param \DOMElement $node
     * @param mixed $object
     * @param ClassMetadata $classMetadata
     * @throws Exception
     */
    private function processAttributes(\DOMElement $node, $object, ClassMetadata $classMetadata)
    {
        /** @var Attribute $attribute */
        foreach ($classMetadata->getAttributes() as $fieldName => $attribute) {
            if (!$node->hasAttribute($attribute->getName())) {
                throw new Exception('Cannot found attribute ' . $attribute->getName(
                ) . ' of node ' . $classMetadata->getName());
            }

            $this->setPropertyValue(
                $classMetadata->getReflection()->getProperty($fieldName),
                $attribute,
                $object,
                $node->getAttribute($attribute->getName())
            );
        }
    }

    /**
     * @param \DOMElement $node
     * @param ClassMetadata $classMetadata
     * @param mixed $object
     * @throws Exception
     */
    private function processElements(\DOMElement $node, ClassMetadata $classMetadata, $object)
    {
        /** @var Element $element */
        foreach ($classMetadata->getElements() as $fieldName => $element) {

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

            $this->attachChildNodesToObject($object, $classMetadata, $childNodes, $element, $fieldName);
        }
    }

    /**
     * @param \DOMElement $node
     * @param mixed $object
     * @param ClassMetadata $classMetadata
     */
    private function processValue(\DOMElement $node, $object, ClassMetadata $classMetadata)
    {
        $valueElement = $classMetadata->getValueElement();
        if (!empty($valueElement)) {
            $fieldValue = '';
            foreach ($node->childNodes as $childNode) {
                if ($childNode instanceof \DOMText) {
                    $fieldValue .= $childNode->textContent;
                }
            }

            $property = $classMetadata->getReflection()->getProperty($valueElement);
            $property->setAccessible(true);
            $property->setValue($object, $fieldValue);
        }
    }

    /**
     * @param \ReflectionProperty $property
     * @param Base $baseMetadata
     * @param mixed $object
     * @param mixed $value
     * @return mixed
     */
    private function setPropertyValue(\ReflectionProperty $property, Base $baseMetadata, $object, $value)
    {
        if ($baseMetadata->getSource() == Base::FIELD_SOURCE) {
            $property->setAccessible(true);
            $property->setValue($object, $value);
        } else {
echo __METHOD__ . ':' . __LINE__ . "\n";
            $object->{'set' . ucfirst($property->getName())}($value);
        }
    }

    /**
     * @param \DOMElement $node
     * @param string $childName
     * @return \DOMElement[]
     */
    private function filterChildNodes(\DOMElement $node, $childName)
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
    private function hasChild(\DOMElement $node, $childName)
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
     * @param ClassMetadata $classMetadata
     * @return object
     */
    public function getNewEntity(ClassMetadata $classMetadata)
    {
        $className = $classMetadata->getClassName();
        $object = new $className();
        return $object;
    }

    /**
     * @param Element $element
     * @param \DOMElement $child
     * @return mixed
     * @throws Exception
     */
    private function getNodeElementValue($element, $child)
    {
        $fieldValue = null;
        if ($element->getType() === ClassMetadata::RUNTIME_TYPE) {
            $fieldValue = $this->getScalarValueFromNode($element->getName(), $child);
        } else {
            $childClassMetadata = $this->classMetadataFactory->getClassMetadata($element->getTypeValue());
            $fieldValue = $this->unmarshallObject(
                $child,
                $this->getNewEntity($childClassMetadata),
                $childClassMetadata
            );
        }

        return $fieldValue;
    }

    /**
     * @param mixed $object
     * @param ClassMetadata $classMetadata
     * @param \DOMElement[] $childNodes
     * @param Element $element
     * @param string $fieldName
     * @return mixed
     */
    private function attachChildNodesToObject(
        $object,
        ClassMetadata $classMetadata,
        $childNodes,
        $element,
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
                $classMetadata->getReflection()->getProperty($fieldName),
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
    private function getScalarValueFromNode($elementName, $child)
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
