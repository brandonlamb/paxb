
namespace PAXB\Filter;

/**
 * Filters the values of a given object
 */
interface FilterInterface
{
    /**
     * Iterates over the properties of the object applying filters and
     * replacing values
     *
     * @param mixed $object
     */
    public function filterEntity(var $object) -> void;

    /**
     * Filters a specific property in an object, replacing the current value
     *
     * @param mixed $object
     * @param string $property
     */
    public function filterProperty(var $object, string! property) -> void;

    /**
     * Runs a given value through one or more filter rules returning the
     * filtered value
     *
     * @param mixed $value
     * @param array|Rules\Rule $filter
     *
     * @return mixed
     */
    public function filterValue(var value, var filter);

    /**
     * Retrieves the metadata factory for class metdatas
     *
     * @return \PAXB\Xml\Mapping\Metadata\FactoryInterface
     */
    public function getMetadataFactory() -> <\PAXB\Xml\Mapping\Metadata\FactoryInterface>;
}
