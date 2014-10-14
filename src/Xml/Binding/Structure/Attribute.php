<?php

namespace PAXB\Xml\Binding\Structure;

class Attribute extends Base
{
    public function __construct($name, $source)
    {
        $this->name = (string) $name;
        $this->source = (int) $source;
    }
}
