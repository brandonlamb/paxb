
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;
use PAXB\Filter\Exception\FilterException;

/**
 * ToLower Filter
 */
class ToLower implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        if this->useEncoding(rule) {
            return mb_strtolower((string) value, rule->encoding);
        }

        return strtolower((string) value);
    }

    /**
     * Verify is encoding is set and if we have the proper
     * function to use it
     *
     * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $rule
     * @return boolean
     *
     * @throws \DMS\Filter\Exception\FilterException
     */
    private function useEncoding(<AnnotationInterface> rule) -> boolean
    {
        var encodings;

        if typeof rule->encoding == "null" {
            return false;
        }

        if !function_exists("mb_strtolower") {
            throw new FilterException("mbstring is required to use ToLower with an encoding.");
        }

        let encodings = array_map("strtolower", mb_list_encodings());

        if !in_array(strtolower(rule->encoding), encodings) {
            throw new FilterException(
                "mbstring does not support the '" . rule->encoding . "' encoding"
            );
        }

        return true;
    }
}
