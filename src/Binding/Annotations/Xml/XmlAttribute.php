<?php

namespace PAXB\Binding\Annotations\Xml;

/**
 * @Annotation
 * @Target("PROPERTY")
 */
class XmlAttribute extends XmlAnnotation
{
    /**
     * @var string
     */
    public $name;
}
