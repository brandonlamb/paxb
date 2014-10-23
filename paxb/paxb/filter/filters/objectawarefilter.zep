
namespace PAXB\Filter\Filters;

/**
 * Interface ObjectAwareFilter
 *
 * Allows filters to be aware of the object they are being applied to.
 */
interface ObjectAwareFilter
{
    /**
     * Set the current object so that the filter can access it
     *
     * @param mixed $object
     * @return mixed
     */
    public function setCurrentObject(var $object);

    /**
     * Retrieves the current Object to be used
     *
     * @return mixed
     */
    public function getCurrentObject();
}
