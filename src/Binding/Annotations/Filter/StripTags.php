<?php

namespace PAXB\Binding\Annotations\Filter;

/**
 * StripTags Rule
 *
 * @Annotation
 */
class StripTags extends AbstractAnnotation
{
    /**
     * String of allowed tags. Ex: <b><i><a>
     *
     * @var string
     */
    public $allowed;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'allowed';
    }
}
