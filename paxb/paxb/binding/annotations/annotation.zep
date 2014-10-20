
namespace PAXB\Binding\Annotations;

use BadMethodCallException;
use RuntimeException;

/**
 * Annotations class.
 */
class Annotation
{
    /**
     * @var string
     */
    public value;

    /**
     * Constructor.
     *
     * @param array data Key-value for properties to be defined in this class.
     */
    public final function __construct(array data)
    {
        var key, value;
        for key, value in data {
            if !isset this->{key} {
                throw new RuntimeException(
                    sprintf("Unknown property '%s' on annotation '%s'.", key, get_class(this))
                );
            }

            let this->{key} = value;
        }
    }

    /**
     * Error handler for unknown property accessor in Annotation class.
     *
     * @param string name Unknown property name.
     * @throws \BadMethodCallException
     */
    public function __get(string! name)
    {
        throw new BadMethodCallException(
            sprintf("Unknown property '%s' on annotation '%s'.", name, get_class(this))
        );
    }

    /**
     * Error handler for unknown property mutator in Annotation class.
     *
     * @param string name  Unknown property name.
     * @param mixed value Property value.
     * @throws \BadMethodCallException
     */
    public function __set(string! name, var value)
    {
        throw new BadMethodCallException(
            sprintf("Unknown property '%s' on annotation '%s'.", name, get_class(this))
        );
    }
}
