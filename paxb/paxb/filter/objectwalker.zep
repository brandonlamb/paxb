
namespace PAXB\Filter;

use PAXB\Filter\Filters\Loader\FilterLoaderInterface;
use PAXB\Filter\Filters\ObjectAwareFilter;
use ReflectionClass;
use UnexpectedValueException;

/**
 * Walks over the properties of an object applying the filters that were defined for them
 */
class ObjectWalker
{
    /**
     * @var object
     */
    protected $object;

    /**
     * @var \ReflectionClass
     */
    protected reflectionClass;

    /**
     * @var FilterLoaderInterface
     */
    protected $filterLoader;

    /**
     * Constructor
     *
     * @param object $object
     * @param FilterLoaderInterface $filterLoader
     */
    public function __construct(var $object, <LoaderInterface> filterLoader)
    {
        let this->$object = $object;
        let this->reflectionClass = new ReflectionClass($object);
        let this->filterLoader = filterLoader;
    }

    /**
     * Applies the selected rules to a property in the object
     *
     * @param string $property
     * @param array $filterRules
     */
    public function applyFilterRules(string! property, array filterRules = []) -> void
    {
        var rule;

        for rule in filterRules {
            this->applyFilterRule(property, rule);
        }
    }

    /**
     * Applies a Filtering Rule to a property
     *
     * @param string $property
     * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $filterRule
     *
     * @throws \UnexpectedValueException
     */
    public function applyFilterRule(string! property, <AnnotationInterface> filterRule) -> void
    {
        var value, filter, filteredValue;

        if typeof this->filterLoader == "null" {
            throw new UnexpectedValueException("A FilterLoader must be provided");
        }

        let value = this->getPropertyValue(property);
        let filter = this->filterLoader->getFilterForRule(filterRule);

        if (filter instanceof ObjectAwareFilter) {
            filter->setCurrentObject(this->$object);
        }

        let filteredValue = filter->apply(filterRule, value);
        this->setPropertyValue(property, filteredValue);
    }

    /**
     * Retrieves the value of the property, overcoming visibility problems
     *
     * @param string $propertyName
     * @return mixed
     */
    private function getPropertyValue(string! propertyName)
    {
        return this->getAccessibleReflectionProperty(propertyName)->getValue(this->$object);
    }

    /**
     * Overrides the value of a property, overcoming visibility problems
     *
     * @param string $propertyName
     * @param mixed $value
     */
    private function setPropertyValue(string! propertyName, var value) -> void
    {
        this->getAccessibleReflectionProperty(propertyName)->setValue(this->$object, value);
    }

    /**
     * Retrieves a property from the object and makes it visible
     *
     * @param string $propertyName
     * @return \ReflectionProperty
     */
    private function getAccessibleReflectionProperty(string! propertyName) -> <\ReflectionProperty>
    {
        var property;

        let property = this->reflectionClass->getProperty(propertyName);
        property->setAccessible(true);

        return property;
    }
}
