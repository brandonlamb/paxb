<?php

namespace PAXB\Xml\Binding\Structure;

use PAXB\Xml\Binding\Metadata\Metadata;

class Element extends Base
{
    /**
     * @var int
     */
    private $type;

    /**
     * @var string
     */
    private $typeValue;

    /**
     * @var string
     */
    private $wrapperName;

    /**
     * @var bool
     */
    private $phpCollection = false;

    public function __construct($name, $source, $type = Metadata::RUNTIME_TYPE, $typeValue = '', $wrapperName = null, $phpCollection = false)
    {
        $this->name = $name;
        $this->type = $type;
        $this->typeValue = $typeValue;
        $this->source = $source;
        $this->wrapperName = $wrapperName;
        $this->phpCollection = $phpCollection;
    }

    /**
     * @return mixed
     */
    public function getType()
    {
        return $this->type;
    }

    /**
     * @return string
     */
    public function getTypeValue()
    {
        return (string) $this->typeValue;
    }

    /**
     * @return mixed
     */
    public function getWrapperName()
    {
        return $this->wrapperName;
    }

    /**
     * @param string $wrapperName
     */
    public function setWrapperName($wrapperName)
    {
        $this->wrapperName = (string) $wrapperName;
    }

    /**
     * @param string $typeValue
     */
    public function setTypeValue($typeValue)
    {
        $this->type = Metadata::DEFINED_TYPE;
        $this->typeValue = (string) $typeValue;
    }

    /**
     * @param boolean $phpCollection
     */
    public function setPhpCollection($phpCollection)
    {
        $this->phpCollection = (bool) $phpCollection;
    }

    /**
     * @return boolean
     */
    public function getPhpCollection()
    {
        return (bool) $this->phpCollection;
    }
}
