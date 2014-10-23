
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Alnum Filter (Alphanumeric)
 */
class AlphaNumeric extends RegExp
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        var whitespaceChar;

        // Check for Whitespace support
        let whitespaceChar = (rule->allowWhitespace) ? " " : "";

        let rule->unicodePattern = "/[^\\p{L}\\p{N}" . whitespaceChar . "]/u";
        let rule->pattern = "/[^a-zA-Z0-9" . whitespaceChar . "]/";

        return parent::apply(rule, value);
    }
}
