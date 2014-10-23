<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * Html Entities Filter
 *
 * @Annotation
 */
class HtmlEntities extends AbstractAnnotation
{
    /**
     * Flags
     *
     * @var int
     */
    public $flags = ENT_COMPAT;

    /**
     * Encoding to be used
     *
     * @var string
     */
    public $encoding = 'UTF-8';

    /**
     * Convert existing entities
     *
     * @var bool
     */
    public $doubleEncode = true;
}
