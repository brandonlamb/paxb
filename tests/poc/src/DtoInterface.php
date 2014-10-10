<?php

/**
 * Interface for Data Transfer Objects
 *
 * @package \Api\Dto
 * @copyright Starbucks Coffee Company
 * @author Brandon Lamb <brlamb@starbucks.com>
 */

namespace Api;

interface DtoInterface
{
    /**
     * Get a DTO property by name
     *
     * @param string $offset
     * @return mixed
     */
    public function get($offset);

    /**
     * Set a DTO property by name
     *
     * @param string $offset
     * @param mixed $value
     * @return \Api\Dto\DtoInterface
     */
    public function set($offset, $value);
}
