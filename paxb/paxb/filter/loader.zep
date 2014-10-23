
namespace PAXB\Filter;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;
use PAXB\Filter\Filters\FilterInterface;

/**
 * Loads the filter that enforces a specific rule.
 */
class Loader implements LoaderInterface
{
    /**
     * {@inheritDoc}
     */
    public function getFilterForRule(<AnnotationInterface> $rule) -> <\PAXB\Filter\Filters\FilterInterface>
    {
        var filterIdentifier;

        let filterIdentifier = rule->getFilter();

        if class_exists(filterIdentifier) {
            return new {filterIdentifier}();
        }

        throw new \UnexpectedValueException("Unable to locate filter for: $filterIdentifier defined in " . get_class(rule));
    }
}
