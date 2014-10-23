
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Html Entities Filter
 */
class HtmlEntities implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        return htmlentities(value, rule->flags, rule->encoding, rule->doubleEncode);
    }
}
