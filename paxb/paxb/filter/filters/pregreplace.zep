
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * PregReplace Filter
 *
 * Replaces based on regular expression, will replace with empty if no
 * replacement is defined.
 */
class PregReplace implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        return preg_replace(rule->regexp, rule->replacement, value);
    }
}
