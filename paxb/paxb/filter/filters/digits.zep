
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Digits Rule
 */
class Digits extends RegExp
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        var whitespaceChar;

        // Check for Whitespace support
        let whitespaceChar = (rule->allowWhitespace) ? " " : "";

        let rule->unicodePattern = "/[^\\p{N}" . whitespaceChar . "]/";
        let rule->pattern = "/[^0-9" . whitespaceChar . "]/";

        return parent::apply(rule, value);
    }
}
