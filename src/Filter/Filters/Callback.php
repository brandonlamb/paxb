<?php

namespace PAXB\Filter\Filters;

use Closure;
use PAXB\Filter\Exception\FilterException;
use PAXB\Filter\Exception\InvalidCallbackException;
use PAXB\Binding\Annotations\Filter\Callback as CallbackRule;
use PAXB\Binding\Annotations\Filter\AnnotationInterface;

/**
 * Callback Filter
 */
class Callback implements FilterInterface, ObjectAwareFilter
{
    /**
     * @var mixed
     */
    protected $currentObject;

    /**
     * Set the current object so that the filter can access it
     *
     * @param mixed $object
     * @return mixed
     */
    public function setCurrentObject($object)
    {
        $this->currentObject = $object;
    }

    /**
     * Retrieves the current Object to be used
     *
     * @return mixed
     */
    public function getCurrentObject()
    {
        return $this->currentObject;
    }

    /**
     * {@inheritDoc}
     */
    public function apply(AnnotationInterface $rule, $value)
    {
        $type = $rule->getInputType();

        if ($type == CallbackRule::SELF_METHOD_TYPE) {
            return $this->useObjectMethod($rule->callback, $value);
        }

        if ($type == CallbackRule::CALLABLE_TYPE) {
            return $this->useCallable($rule->callback, $value);
        }

        if ($type == CallbackRule::CLOSURE_TYPE) {
            return $this->useClosure($rule->callback, $value);
        }

        throw new InvalidCallbackException("Unsupported callback provided, failed to filter property");
    }

    /**
     * Filters by executing a method in the object
     *
     * @param string $method
     * @param mixed $value
     * @throws \PAXB\Filter\Exception\FilterException
     * @throws \PAXB\Filter\Exception\InvalidCallbackException
     * @return mixed
     */
    protected function useObjectMethod($method, $value)
    {
        $currentObject = $this->getCurrentObject();

        if ($currentObject === null) {
            throw new FilterException(
                "The target object was not provided to the filter, can't execute method. Please report this."
            );
        }

        if (!method_exists($currentObject, $method)) {
            throw new InvalidCallbackException(
                sprintf(
                    "CallbackFilter: Method '%s' not found in object of type '%s'",
                    $method,
                    get_class($currentObject)
                )
            );
        }

        return $currentObject->$method($value);
    }

    /**
     * Filters using a callable.
     *
     * @param callable $callable
     * @param mixed $value
     * @throws \PAXB\Filter\Exception\InvalidCallbackException
     * @return mixed
     */
    protected function useCallable($callable, $value)
    {
        if (!is_callable($callable, false, $input)) {
            throw new InvalidCallbackException("The callable $input could not be resolved.");
        }

        return call_user_func($callable, $value);
    }

    /**
     * @param Closure $closure
     * @param mixed $value
     * @throws \PAXB\Filter\Exception\InvalidCallbackException
     * @return mixed
     */
    protected function useClosure($closure, $value)
    {
        if (!($closure instanceof Closure)) {
            throw new InvalidCallbackException("CallbackFilter: the provided closure is invalid");
        }

        return $closure($value);
    }
}
