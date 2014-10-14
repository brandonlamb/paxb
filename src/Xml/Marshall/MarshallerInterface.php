<?php

namespace PAXB\Xml\Marshall;

interface MarshallerInterface
{
    /**
     * @param mixed $object
     * @param bool $format
     * @return string
     */
    public function marshall($object, $format = false);
}
