<?php

namespace PAXB\Xml\Unmarshall;

interface UnmarshallerInterface
{
    /**
     * @param string $string
     * @param string $rootClass
     * @return mixed
     */
    public function unmarshall($string, $rootClass);
}
