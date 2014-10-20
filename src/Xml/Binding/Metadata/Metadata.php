<?php

namespace PAXB\Xml\Binding\Metadata;

use PAXB\Filter\Annotations\AnnotationsInterface;
use PAXB\Filter\Rule\RuleInterface;
use PAXB\Xml\Binding\Structure\Element;
use ReflectionClass;

class Metadata implements MetadataInterface
{
    const RUNTIME_TYPE   = 1;
    const DEFINED_TYPE   = 2;

    /**
     * @var string
     */
    private $className;

    /**
     * @var string
     */
    private $name;

    /**
     * @var array
     */
    private $attributes = [];

    /**
     * @var Element[]
     */
    private $elements = [];

    /**
     * @var string
     */
    private $valueElement;

    /**
     * Properties that contain filtering rules
     * @var array
     */
    private $filteredProperties = [];

    /**
     * @var \ReflectionClass
     */
    private $reflection;

    /**
     * @param string $className
     */
    public function __construct($className)
    {
        $this->className = trim($className);
    }

    /**
     * @return array
     */
    public function getAttributes()
    {
        return (array) $this->attributes;
    }

    /**
     * Get name of class represented in this Metadata object
     *
     * @return string
     */
    public function getClassName()
    {
        return (string) $this->className;
    }

    /**
     * @return string
     */
    public function getName()
    {
        return (string) $this->name;
    }

    /**
     * @return \PAXB\Xml\Binding\Metadata\Element[]
     */
    public function getElements()
    {
        return $this->elements;
    }

    /**
     * @return string
     */
    public function getValueElement()
    {
        return (string) $this->valueElement;
    }

    /**
     * Returns a ReflectionClass instance for this class
     *
     * @return \ReflectionClass
     */
    public function getReflectionClass()
    {
        if (null === $this->reflection) {
            $this->reflection = new ReflectionClass($this->getClassName());
        }

        return $this->reflection;
    }

    /**
     * {@inheritDoc}
     */
    public function addPropertyRule($property, AnnotationsInterface $rule)
    {
        if (!isset ($this->filteredProperties[$property])) {
            $this->filteredProperties[$property] = ['rules' => []];
        }
        $this->filteredProperties[$property]['rules'][] = $rule;

        return $this;
    }

    /**
     * {@inheritDoc}
     */
    public function getPropertyRules($property)
    {
        if (!isset($this->filteredProperties[$property])) {
            return null;
        }

        return $this->filteredProperties[$property]['rules'];
    }

    /**
     * {@inheritDoc}
     */
    public function mergeRules(MetadataInterface $metadata)
    {
        foreach ($metadata->getFilteredProperties() as $property) {
            foreach ($metadata->getPropertyRules($property) as $rule) {
                $this->addPropertyRule($property, clone $rule);
            }
        }

        return $this;
    }

    /**
     * {@inheritDoc}
     */
    public function getFilteredProperties()
    {
        return array_keys($this->filteredProperties);
    }

    /**
     * @param string $fieldName
     * @param \PAXB\Xml\Binding\Structure\Attribute $attribute
     */
    public function addAttributes($fieldName, $attribute)
    {
        $this->attributes[(string) $fieldName] = $attribute;
    }

    /**
     * @param string $fieldName
     * @param \PAXB\Xml\Binding\Structure\Element $element
     */
    public function addElement($fieldName, $element)
    {
        $this->elements[(string) $fieldName] = $element;
    }

    /**
     * @param string $name
     */
    public function setName($name)
    {
        $this->name = trim($name);
    }

    /**
     * @param string $valueElement
     */
    public function setValueElement($valueElement)
    {
        $this->valueElement = trim($valueElement);
    }
}
