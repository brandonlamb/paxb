<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * ToUpper Rule
 *
 * @Annotation
 */
class ToUpper extends AbstractAnnotation
{
    /**
     * Encoding to be used
     *
     * @var string
     */
    public $encoding;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'encoding';
    }
}
