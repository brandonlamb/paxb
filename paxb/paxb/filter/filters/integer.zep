
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Integer Filter
 * Converts content into an Int
 * @subpackage Filter
 */
class Integer implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        return (int) value;
    }
}
