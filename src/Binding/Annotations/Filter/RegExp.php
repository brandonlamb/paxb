<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * RegExp Rule
 *
 * Filter using preg_replace and unicode or non-unicode patterns
 *
 * @Annotation
 */
class RegExp extends AbstractAnnotation
{
    /**
     * Unicode version of Pattern
     *
     * @var string
     */
    public $unicodePattern;

    /**
     * Reg Exp Pattern
     *
     * @var string
     */
    public $pattern;
}
