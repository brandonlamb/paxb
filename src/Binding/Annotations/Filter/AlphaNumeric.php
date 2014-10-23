<?php

namespace PAXB\Filter\Annotations;

/**
 * AlphaNumeric Rule (Alphanumeric)
 *
 * @Annotation
 */
class AlphaNumeric extends RegExp
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
