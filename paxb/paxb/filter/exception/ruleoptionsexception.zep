
namespace PAXB\Filter\Exception;

/**
 * Base Exception for errors with rule options
 */
class RuleOptionsException extends FilterException
{
    /**
     * @var array
     */
    private options;

    /**
     * Constructor
     *
     * @param string $message
     * @param array $options
     */
    public function __construct(string! message, array options)
    {
        parent::__construct(message);
        let this->options = options;
    }

    /**
     * Retrieve options that triggered exception
     *
     * @return array
     */
    public function getOptions() -> array
    {
        return this->options;
    }
}
