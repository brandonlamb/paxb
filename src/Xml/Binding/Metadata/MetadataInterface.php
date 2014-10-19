<?php

/**
 * Interface for methods required by a Metadata class
 */

namespace PAXB\Xml\Binding\Metadata;

use PAXB\Filter\Rule\RuleInterface;
use ReflectionClass;

interface MetadataInterface
{
    /**
     * Retrieve a list of the object's properties that have filters attached
     * to them
     *
     * @return array
     */
    public function getFilteredProperties();

    /**
     * Adds a new rule to a property
     *
     * @param string $property
     * @param RuleInterface $rule
     * @return MetadataInterface
     */
    public function addPropertyRule($property, RuleInterface $rule);

    /**
     * Retrieve s list of filtering rules attached to a property
     *
     * @param string $property
     * @return array
     */
    public function getPropertyRules($property);

    /**
     * Merges rules from another metadata object into this one
     *
     * @param MetadataInterface $metadata
     * @return MetadataInterface
     */
    public function mergeRules(MetadataInterface $metadata);

    /**
     * Get name of class represented in this Metadata object
     *
     * @return string
     */
    public function getClassName();

    /**
     * Returns a ReflectionClass instance for this class.
     *
     * @return ReflectionClass
     */
    public function getReflectionClass();
}
