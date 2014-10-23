<?php

namespace PAXB\Filter\Annotations;

/**
 * PregReplace Rule
 * Replaces based on regular expression, will replace with empty if no
 * replacement is defined.
 *
 * @Annotation
 */
class PregReplace extends AbstractAnnotation
{
    /**
     * Regular Expression to use
     *
     * @var string
     */
    public $regexp;

    /**
     * Replacement
     *
     * @var string
     */
    public $replacement;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'regexp';
    }
}
