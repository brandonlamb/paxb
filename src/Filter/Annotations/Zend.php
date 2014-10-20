<?php

namespace PAXB\Filter\Annotations;

/**
 * Zend Rule
 *
 * Allows the use for Zend Filters
 *
 * @Annotation
 */
class Zend extends AbstractAnnotation
{
    /**
     * Zend\Filter class, can be either a FQN or just Boolean for example
     *
     * @var string
     */
    public $class;

    /**
     * Array of options to be passed into the Zend Filter
     *
     * @var array
     */
    public $zendOptions = [];

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'class';
    }
}
