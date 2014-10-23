
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Trim Filter
 */
class Trim implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        // trim() only operates in default mode. If no second argument is passed,
        // it cannot be passed as null
        if typeof rule->charlist == "null" {
            return trim(value);
        }

        return trim(value, rule->charlist);
    }
}
