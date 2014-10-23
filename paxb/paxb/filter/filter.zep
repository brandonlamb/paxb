
namespace PAXB\Filter;

/**
 * Filter Object, responsible for retrieving the filtering rules
 * for the object and applying them
 */

use PAXB\Filter\Annotations\AnnotationInterface;
use PAXB\Filter\Filters\Loader\FilterLoaderInterface;
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
     * @var \PAXB\Xml\Mapping\Metadata\FactoryInterface
     */
    protected metadataFactory;

    /**
     * @var FilterLoaderInterface
     */
    protected filterLoader;

    /**
     * Constructor
     *
     * @param \PAXB\Xml\Mapping\Metadata\FactoryInterface $metadataFactory
     * @param FilterLoaderInterface $filterLoader
     */
    public function __construct(<FactoryInterface> $metadataFactory, <FilterLoaderInterface> $filterLoader)
    {
        let this->metadataFactory = metadataFactory;
        let this->filterLoader    = filterLoader;
    }

    /**
     * {@inheritDoc}
     */
    public function filterEntity(var $object) -> void
    {
        this->walkObject($object);
    }

    /**
     * {@inheritDoc}
     */
    public function filterProperty(var $object, string! property) -> void
    {
        this->walkObject($object, property);
    }

    /**
     * {@inheritDoc}
     */
    public function filterValue(var value, var rule)
    {
        var filter;
        if (rule instanceof AnnotationInterface) {
            let filter = this->filterLoader->getFilterForRule(rule);
            return filter->apply(rule, value);
        }

        return this->walkRuleChain(value, rule);
    }

    /**
     * {@inheritDoc}
     */
    public function getMetadataFactory() -> <\PAXB\Binding\Metadata\FactoryInterface>
    {
        return this->metadataFactory;
    }

    /**
     * Iterates over annotated properties in an object filtering the selected
     * values
     *
     * @param object $object
     * @param string $limitProperty
     */
    protected function walkObject(var $object, string! limitProperty = null) -> void
    {
        var metadata, walker, property, properties;

        if typeof $object == "null" {
            return;
        }

        let metadata = this->metadataFactory->getMetadata(get_class($object));

        // Get a Object Handler/Walker
        let walker = new ObjectWalker($object, this->filterLoader);

        // Get all filtered properties or limit with selected
        let properties = (typeof limitProperty !== "null") ? [limitProperty] : metadata->getFilteredProperties();

        // Iterate over properties with filters
        for property in properties {
            walker->applyFilterRules(property, metadata->getPropertyRules(property));
        }
    }

    /**
     * Iterates over an array of filters applying all to the value
     *
     * @param mixed $value
     * @param array $rules
     * @return mixed
     */
    protected function walkRuleChain(var value, array rules)
    {
        var rule, filter, value;

        for rule in rules {
            let filter = this->filterLoader->getFilterForRule(rule);
            let value = filter->apply(rule, value);
        }

        return value;
    }
}
