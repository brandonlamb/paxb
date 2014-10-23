
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * RegExp Filter
 *
 * Filter using preg_replace and unicode or non-unicode patterns
 */
class RegExp implements FilterInterface
{
    /**
     * Defines if Unicode is supported
     *
     * @var boolean
     */
    protected static unicodeEnabled;

    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        var pattern;

        // Build pattern
        if this->checkUnicodeSupport() && typeof rule->unicodePattern != "null" {
            let pattern = rule->unicodePattern;
        } else {
            let pattern = rule->pattern;
        }

        return preg_replace(pattern, "", value);
    }

    /**
     * Verifies that Regular Expression functions support unicode
     * @return boolean
     */
    public function checkUnicodeSupport()
    {
        if typeof self::unicodeEnabled != "null" {
            if preg_match("/\\pL/u", "a") {
                let self::unicodeEnabled = true;
            } else {
                let self::unicodeEnabled = false;
            }
        }

        return self::unicodeEnabled;
    }
}
