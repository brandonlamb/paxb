
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Alpha Filter
 */
class Alpha extends RegExp
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        var whitespaceChar;

        // Check for Whitespace support
        let whitespaceChar = (rule->allowWhitespace) ? " " : "";

        let rule->unicodePattern = "/[^\\p{L}" . whitespaceChar . "]/u";
        let rule->pattern = "/[^a-zA-Z" . whitespaceChar . "]/";

        return parent::apply(rule, value);
    }
}
