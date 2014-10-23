<?php

namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Float Filter
 * Converts content into a Float
 */
class Float implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(AnnotationInterface $rule, $value)
    {
        if (is_array($value) || is_object($value)) {
            return null;
        }

        return floatval($value);
    }
}
