<?php

namespace PAXB\Filter;

/**
 * Filter Object, responsible for retrieving the filtering rules
 * for the object and applying them
 *
 * @package DMS
 * @subpackage Filter
 *
 */

use PAXB\Filter\Filters\Loader\FilterLoaderInterface;
use PAXB\Filter\Rules\RuleInterface;
use PAXB\Binding\Metadata\FactoryInterface;

/**
 * Class Filter
 *
 * Executor, receives objects that need filtering and executes attached rules.
 *
 * @package PAXB\Filter
 */
class Filter implements FilterInterface
{
    /**
     * @var Mapping\ClassMetadataFactory
     */
    protected $metadataFactory;

    /**
     * @var FilterLoaderInterface
     */
    protected $filterLoader;

    /**
     * Constructor
     *
     * @param Mapping\ClassMetadataFactory $metadataFactory
     * @param FilterLoaderInterface $filterLoader
     */
    public function __construct(MetadataFactoryInterface $metadataFactory, FilterLoaderInterface $filterLoader)
    {
        $this->metadataFactory = $metadataFactory;
        $this->filterLoader    = $filterLoader;
    }

    /**
     * {@inheritDoc}
     */
    public function filterEntity($object)
    {
        $this->walkObject($object);
    }

    /**
     * {@inheritDoc}
     */
    public function filterProperty($object, $property)
    {
        $this->walkObject($object, $property);
    }

    /**
     * {@inheritDoc}
     */
    public function filterValue($value, $rule)
    {
        if ($rule instanceof RuleInterface) {
            $filter = $this->filterLoader->getFilterForRule($rule);
            return $filter->apply($rule, $value);
        }

        return $this->walkRuleChain($value, $rule);
    }

    /**
     * {@inheritDoc}
     */
    public function getMetadataFactory()
    {
        return $this->metadataFactory;
    }

    /**
     * Iterates over annotated properties in an object filtering the selected
     * values
     *
     * @param object $object
     * @param string $limitProperty
     */
    protected function walkObject($object, $limitProperty = null)
    {
        if ($object === null) {
            return;
        }

        $metadata = $this->metadataFactory->getMetadata(get_class($object));

        // Get a Object Handler/Walker
        $walker = new ObjectWalker($object, $this->filterLoader);

        // Get all filtered properties or limit with selected
        $properties = ($limitProperty !== null) ? array($limitProperty) : $metadata->getFilteredProperties();

        // Iterate over properties with filters
        foreach ($properties as &$property) {
            $walker->applyFilterRules($property, $metadata->getPropertyRules($property));
        }
    }

    /**
     * Iterates over an array of filters applying all to the value
     *
     * @param mixed $value
     * @param array $rules
     * @return mixed
     */
    protected function walkRuleChain($value, array $rules)
    {
        foreach ($rules as &$rule) {
            $filter = $this->filterLoader->getFilterForRule($rule);
            $value = $filter->apply($rule, $value);
        }

        return $value;
    }
}
