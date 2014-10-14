<?php

namespace PAXB\Xml\Binding\Structure;

class Base
{
    const GETTER_SOURCE = 1;
    const FIELD_SOURCE  = 2;

    protected $name;
    protected $source;

    /**
     * @return string
     */
    public function getName()
    {
        return (string) $this->name;
    }

    /**
     * @return int
     */
    public function getSource()
    {
        return (int) $this->source;
    }

    /**
     * @param string $name
     */
    public function setName($name)
    {
        $this->name = (string) $name;
    }

    /**
     * @param int $source
     */
    public function setSource($source)
    {
        $this->source = (int) $source;
    }
}
