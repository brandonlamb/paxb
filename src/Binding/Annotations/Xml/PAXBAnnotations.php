<?php

namespace PAXB\Binding\Annotations\Xml;

use PAXB\Binding\Annotations\Annotation;
use PAXB\Binding\Annotations\Xml\AnnotationInterface;

/**
 * @Annotation
 */
class XmlAnnotation extends Annotation implements AnnotationInterface {}

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

/**
 * @Annotation
 */
class XmlElementWrapper extends XmlAnnotation
{
    /**
     * @var string
     */
    public $name;
}

/**
 * @Annotation
 */
class XmlPhpCollection extends XmlAnnotation {}

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

/**
 * @Annotation
 */
class XmlTransient extends XmlAnnotation {}

/**
 * @Annotation
 */
class XmlValue extends XmlAnnotation {}
