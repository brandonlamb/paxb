
namespace PAXB\Filter;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;
use PAXB\Filter\Filters\FilterInterface;

/**
 * Interface LoaderInterface
 *
 * Defines the required interface for a loader capable of finding the executor of a specific rule.
 */
interface LoaderInterface
{
    /**
     * Finds the filter responsible for executing a specific rule
     *
     * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $rule
     * @return \PAXB\Filter\Filters\FilterInterface
     *
     * @throws \UnexpectedValueException If filter can't be located
     */
    public function getFilterForRule(<AnnotationInterface> rule) -> <\PAXB\Filter\Filters\FilterInterface>;
}
