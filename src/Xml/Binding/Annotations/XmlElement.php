<?php

namespace PAXB\Xml\Binding\Annotations;

/**
 * @Annotation
 * @Target({"PROPERTY", "METHOD"})
 */
class XmlElement extends XmlAnnotation
{
    /**
     * @var string
     */
    public $name;

    /**
     * @var string
     */
    public $type;
}
