<?php

/**
 * Abstract class for Data Transfer Objects
 *
 * @package \Api\Dto
 * @copyright Starbucks Coffee Company
 * @author Brandon Lamb <brlamb@starbucks.com>
 */

namespace Api;

abstract class AbstractDto implements DtoInterface
{
    /**
     * Constructor
     *
     * @param array $data
     */
    public function __construct(array $data = [])
    {
        foreach ($data as $key => $value) {
            $this->set($key, $value);
        }
        #method_exists($this, 'init') && $this->init();
    }

    /**
     * Magic getter
     *
     * @param string $offset
     * @return mixed
     */
    public function __get($offset)
    {
        return $this->get($offset);
    }

    /**
     * Magic setter
     *
     * @param string $offset
     * @param mixed $value
     */
    public function __set($offset, $value)
    {
        $this->set($offset, $value);
    }

    /**
     * Get a DTO property by name
     *
     * This method supports calling a getProperty() method if implemented,
     * otherwise it will get the property directly.
     *
     * @param string $offset
     * @return mixed
     * @throws \Api\Dto\Exception
     */
    public function get($offset)
    {
        if (!property_exists($this, $offset)) {
            throw new Exception('DTO has no property "' . $offset . '" defined');
        }

        $method = 'get' . $offset;
        return method_exists($this, $method) ? $this->{$method}() : $this->{$offset};
    }

    /**
     * Set a DTO property by name
     *
     * This method supports calling a setProperty($value) method if implemented,
     * otherwise it will set the property directly.
     *
     * @param string $offset
     * @param mixed $value
     * @return \Api\Dto\DtoInterface
     * @throws \Api\Dto\Exception
     */
    public function set($offset, $value)
    {
        if (!property_exists($this, $offset)) {
            throw new Exception('DTO has no property "' . $offset . '" defined');
        }

        $method = 'set' . $offset;
        if (method_exists($this, $method)) {
            $this->{$method}($value);
        }  else {
            $this->{$offset} = $value;
        }

        return $this;
    }
}
