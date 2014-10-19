
/**
 * Interface for methods required by a Metadata class
 */

namespace PAXB\Xml\Binding\Metadata;

use PAXB\Filter\Annotations\AnnotationsInterface;

interface MetadataInterface
{
    /**
     * Retrieve a list of the object's properties that have filters attached
     * to them
     *
     * @return array
     */
    public function getFilteredProperties() -> array;

    /**
     * Adds a new rule to a property
     *
     * @param string $property
     * @param AnnotationsInterface $rule
     * @return MetadataInterface
     */
    public function addPropertyRule(string! property, AnnotationsInterface rule) -> <\PAXB\Xml\Binding\MetadataInterface>;

    /**
     * Retrieve s list of filtering rules attached to a property
     *
     * @param string $property
     * @return array
     */
    public function getPropertyRules(string! property) -> array;

    /**
     * Merges rules from another metadata object into this one
     *
     * @param MetadataInterface $metadata
     * @return MetadataInterface
     */
    public function mergeRules(MetadataInterface metadata) -> <\PAXB\Xml\Binding\MetadataInterface>;

    /**
     * Get name of class represented in this Metadata object
     *
     * @return string
     */
    public function getClassName() -> string;

    /**
     * Returns a ReflectionClass instance for this class.
     *
     * @return ReflectionClass
     */
    public function getReflectionClass() -> <\ReflectionClass>;
}
