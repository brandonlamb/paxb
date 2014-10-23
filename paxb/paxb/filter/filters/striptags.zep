
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * StripTags Filter
 */
class StripTags implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        return strip_tags(value, rule->allowed);
    }
}
