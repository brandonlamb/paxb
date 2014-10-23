<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * ToLower Rule
 *
 * @Annotation
 */
class ToLower extends AbstractAnnotation
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
