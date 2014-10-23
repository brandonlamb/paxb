<?php

namespace PAXB\Filter\Annotations;

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
