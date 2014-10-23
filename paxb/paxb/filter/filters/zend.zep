
namespace PAXB\Filter\Filters;

use PAXB\Binding\Annotations\Filter\AnnotationInterface;
use PAXB\Filter\Exception\InvalidZendFilterException;
use ReflectionException;

/**
 * Zend Filter
 *
 * Instantiates and runs Zend Filters (from ZF2)
 */
class Zend implements FilterInterface
{
    /**
     * {@inheritDoc}
     */
    public function apply(<AnnotationInterface> rule, var value)
    {
        return this->getZendInstance(rule->className, rule->zendOptions)->filter(value);
    }

    /**
     * Instantiates a configured Zend Filter, if it exists
     *
     * @param string className
     * @param array $options
     * @return \Zend\Filter\FilterInterface
     * @throws \DMS\Filter\Exception\InvalidZendFilterException
     */
    public function getZendInstance(string! className, array options)
    {
        var reflectionClass, filter, e;

        if strpos(className, "Zend\\Filter") === false {
            let className = "Zend\\Filter\\" . className;
        }

        if !class_exists(className) {
            throw new InvalidZendFilterException("Could not find or autoload: className");
        }

        try {
            let reflectionClass = new \ReflectionMethod(className, "setOptions");

            let filter = new {className}();
            filter->setOptions(options);

            return filter;
        } catch ReflectionException, e {
            return new {className}(options);
        }
    }
}
