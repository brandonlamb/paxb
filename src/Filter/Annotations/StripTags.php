<?php

namespace PAXB\Filter\Annotations;

/**
 * StripTags Rule
 *
 * @Annotation
 */
class StripTags extends AbstarctAnnotation
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
