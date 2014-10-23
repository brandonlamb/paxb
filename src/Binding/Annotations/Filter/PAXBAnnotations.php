<?php

namespace PAXB\Binding\Annotations\Filter;

use Closure;
use PAXB\Filter\Exception\InvalidCallbackException;
use PAXB\Filter\Exception\InvalidOptionsException;
use PAXB\Filter\Exception\MissingOptionsException;
use PAXB\Filter\Exception\RuleDefinitionException;

/**
 * Base class for a Filtering Rule, it implements common behaviour
 *
 * Rules are classes that define the metadata supported by
 * each filter and are used to annotate objects.
 */
abstract class AbstractAnnotation implements AnnotationInterface
{
    /**
     * Initializes the filter rule with its options
     *
     * @param mixed $options The options (as associative array) or the value for the default option (any other type)
     * @throws InvalidOptionsException When you pass the names of non-existing options
     * @throws MissingOptionsException When you don't pass any of the options returned by getRequiredOptions()
     */
    public function __construct($options = null)
    {
        $result = $this->parseOptions($options);

        if (count($result->invalidOptions) > 0) {
            throw new InvalidOptionsException(
                sprintf(
                    'The options "%s" do not exist in rule %s',
                    implode('", "', $result->invalidOptions),
                    get_class($this)
                ),
                $result->invalidOptions
            );
        }

        if (count($result->missingOptions) > 0) {
            throw new MissingOptionsException(
                sprintf(
                    'The options "%s" must be set for rule %s',
                    implode('", "', array_keys($result->missingOptions)),
                    get_class($this)
                ),
                array_keys($result->missingOptions)
            );
        }
    }

    /**
     * Parses provided options into their properties and returns results
     * for the parsing process
     *
     * @param mixed $options
     * @return \stdClass
     */
    private function parseOptions($options)
    {
        $parseResult = new \stdClass();
        $parseResult->invalidOptions = [];
        $parseResult->missingOptions = array_flip((array)$this->getRequiredOptions());

        // Doctrine parses constructor parameter into 'value' array param, restore it
        if (is_array($options) && count($options) == 1 && isset($options['value'])) {
            $options = $options['value'];
        }

        // Parse Option Array
        if (is_array($options) && count($options) > 0 && is_string(key($options))) {
            $this->parseOptionsArray($options, $parseResult);
            return $parseResult;
        }

        // Parse Single Value
        if (null !== $options && !(is_array($options) && count($options) === 0)) {
            $this->parseSingleOption($options, $parseResult);
            return $parseResult;
        }

        return $parseResult;
    }

    /**
     * Parses Options in the array format
     *
     * @param array $options
     * @param \stdClass $result
     */
    private function parseOptionsArray($options, \stdClass $result)
    {
        foreach ($options as $option => $value) {

            if (!property_exists($this, $option)) {
                $result->invalidOptions[] = $option;
                continue;
            }

            // Define Option
            $this->$option = $value;
            unset($result->missingOptions[$option]);
        }
    }

    /**
     * Parses single option received
     *
     * @param string $options
     * @param \stdClass $result
     * @throws \PAXB\Filter\Exception\RuleDefinitionException
     */
    private function parseSingleOption($options, \stdClass $result)
    {
        $option = $this->getDefaultOption();

        // No Default set, unsure what to do
        if (null === $option) {
            throw new RuleDefinitionException(
                sprintf('No default option is configured for rule %s', get_class($this))
            );
        }

        // Default option points to invalid one
        if (!property_exists($this, $option)) {
            $result->invalidOptions[] = $option;
            return;
        }

        // Define Option
        $this->$option = $options;
        unset($result->missingOptions[$option]);
    }

    /**
     * Returns the name of the required options
     *
     * Override this method if you want to define required options.
     *
     * @return array
     * @see __construct()
     */
    public function getRequiredOptions()
    {
        return [];
    }

    /**
     * Returns the name of the default option
     *
     * Override this method to define a default option.
     *
     * @return string
     * @see __construct()
     */
    public function getDefaultOption()
    {
        return null;
    }

    /**
     * Retrieves the Filter class that is responsible for executing this filter
     * It may also be a service name. By default it loads a class with the
     * same name from the Filters namespace.
     *
     * @return string
     */
    public function getFilter()
    {
        return str_replace('Rules', 'Filters', get_class($this));
    }
}

/**
 * RegExp Rule
 *
 * Filter using preg_replace and unicode or non-unicode patterns
 *
 * @Annotation
 */
class RegExp extends AbstractAnnotation
{
    /**
     * Unicode version of Pattern
     *
     * @var string
     */
    public $unicodePattern;

    /**
     * Reg Exp Pattern
     *
     * @var string
     */
    public $pattern;
}

/**
 * AlphaNumeric Rule (Alphanumeric)
 *
 * @Annotation
 */
class AlphaNumeric extends RegExp
{
    /**
     * Allow Whitespace or not
     *
     * @var bool
     */
    public $allowWhitespace = true;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'allowWhitespace';
    }
}

/**
 * Alpha Rule
 *
 * @Annotation
 */
class Alpha extends RegExp
{
    /**
     * Allow Whitespace or not
     *
     * @var bool
     */
    public $allowWhitespace = true;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'allowWhitespace';
    }
}

/**
 * Boolean Rule
 *
 * @Annotation
 */
class Boolean extends AbstractAnnotation {}

/**
 * Callback Rule
 *
 * @Annotation
 */
class Callback extends AbstractAnnotation
{
    const SELF_METHOD_TYPE = 'self_method';
    const CALLABLE_TYPE    = 'callable';
    const CLOSURE_TYPE     = 'closure';

    /**
     * Callback, can be:
     * - string: method of filtered object or function
     * - array: [Class, Method] to be called
     * - Closure
     *
     * @var string
     */
    public $callback;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'callback';
    }

    /**
     * Figures out which type of input was provided
     *
     * @return string
     * @throws \PAXB\Filter\Exception\InvalidCallbackException
     */
    public function getInputType()
    {
        switch (true) {
            case $this->callback instanceof Closure:
                return self::CLOSURE_TYPE;

            case is_callable($this->callback, false):
                return self::CALLABLE_TYPE;

            case is_string($this->callback):
                return self::SELF_METHOD_TYPE;
        }

        throw new InvalidCallbackException(
            "The input provided for Callback filter is not supported or the callable not valid.
            Please refer to the class documentation."
        );
    }
}

/**
 * Digits
 *
 * @Annotation
 */
class Digits extends RegExp
{
    /**
     * Allow Whitespace or not
     *
     * @var bool
     */
    public $allowWhitespace = true;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'allowWhitespace';
    }
}

/**
 * Float Rule
 * Converts content into a Float
 *
 * @Annotation
 */
class Float extends AbstractAnnotation {}

/**
 * Html Entities Filter
 *
 * @Annotation
 */
class HtmlEntities extends AbstractAnnotation
{
    /**
     * Flags
     *
     * @var int
     */
    public $flags = ENT_COMPAT;

    /**
     * Encoding to be used
     *
     * @var string
     */
    public $encoding = 'UTF-8';

    /**
     * Convert existing entities
     *
     * @var bool
     */
    public $doubleEncode = true;
}

/**
 * Int Rule
 * Converts content into an Int
 *
 * @Annotation
 */
class Integer extends AbstractAnnotation {}

/**
 * PregReplace Rule
 * Replaces based on regular expression, will replace with empty if no
 * replacement is defined.
 *
 * @Annotation
 */
class PregReplace extends AbstractAnnotation
{
    /**
     * Regular Expression to use
     *
     * @var string
     */
    public $regexp;

    /**
     * Replacement
     *
     * @var string
     */
    public $replacement;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'regexp';
    }
}


/**
 * StripNewlines Rule
 *
 * @Annotation
 */
class StripNewlines extends AbstractAnnotation {}

/**
 * StripTags Rule
 *
 * @Annotation
 */
class StripTags extends AbstractAnnotation
{
    /**
     * String of allowed tags. Ex: <b><i><a>
     *
     * @var string
     */
    public $allowed;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'allowed';
    }
}

/**
 * ToLower Rule
 *
 * @Annotation
 */
class ToLower extends AbstractAnnotation
{
    /**
     * Encoding to be used
     *
     * @var string
     */
    public $encoding;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'encoding';
    }
}

/**
 * ToUpper Rule
 *
 * @Annotation
 */
class ToUpper extends AbstractAnnotation
{
    /**
     * Encoding to be used
     *
     * @var string
     */
    public $encoding;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'encoding';
    }
}

/**
 * Trim Rule
 *
 * @Annotation
 */
class Trim extends AbstractAnnotation
{
    /**
     * Comma separated string of allowed tags
     *
     * @var string
     */
    public $charlist;

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'charlist';
    }
}

/**
 * Zend Rule
 *
 * Allows the use for Zend Filters
 *
 * @Annotation
 */
class Zend extends AbstractAnnotation
{
    /**
     * Zend\Filter class, can be either a FQN or just Boolean for example
     *
     * @var string
     */
    public $class;

    /**
     * Array of options to be passed into the Zend Filter
     *
     * @var array
     */
    public $zendOptions = [];

    /**
     * {@inheritDoc}
     */
    public function getDefaultOption()
    {
        return 'class';
    }
}
