<?php

namespace PAXB\Binding\Annotations\Xml;

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
