<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * Alpha Rule
 *
 * @Annotation
 */
class Alpha extends RegExp
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
