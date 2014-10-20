<?php

namespace PAXB\Filter\Annotations;

/**
 * Trim Rule
 *
 * @Annotation
 */
class Trim extends AbstractAnnotation
{
    /**
     * Comma separated string of allowed tags
     *
     * @var string
     */
    public $charlist;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'charlist';
    }
}