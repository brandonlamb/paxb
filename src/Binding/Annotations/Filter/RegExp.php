<?php

namespace PAXB\Filter\Annotations;

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
