<?php

namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Boolean Filter
 */
class Boolean implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(AnnotationInterface $rule, $value)
    {
        return (boolean) $value;
    }
}
