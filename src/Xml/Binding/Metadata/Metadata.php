<?php

namespace PAXB\Xml\Binding\Metadata;

use PAXB\Xml\Binding\Structure\Element;

class Metadata
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
     * @return \ReflectionClass
     */
    public function getReflection()
    {
        if (null === $this->reflection) {
            $this->reflection = new \ReflectionClass($this->className);
        }

        return $this->reflection;
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
