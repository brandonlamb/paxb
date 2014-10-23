<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * Digits
 *
 * @Annotation
 */
class Digits extends RegExp
{
    /**
     * Allow Whitespace or not
     *
     * @var bool
     */
    public $allowWhitespace = true;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'allowWhitespace';
    }
}
