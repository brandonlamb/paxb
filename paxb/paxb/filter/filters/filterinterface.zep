
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Base Filter Class
 *
 * Abstract class that defined the basic needs of a "Filter"
 * Filter classes are the enforcers of rules. This means they
 * are the classes that know how a given rule is applied to
 * a value.
 *
 */
interface FilterInterface
{
    /**
     * Enforces the desired filtering on the the value  returning a filtered value.
     *
     * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $rule
     * @param mixed $value
     *
     * @return mixed
     */
    public function apply(<AnnotationInterface> rule, var value);
}
