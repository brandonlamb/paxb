<?php

namespace PAXB\Binding\Annotations\Xml;

/**
 * @Annotation
 * @Target("CLASS")
 */
class XmlRootElement extends XmlAnnotation
{
    /**
     * @var string
     */
    public $name;
}
