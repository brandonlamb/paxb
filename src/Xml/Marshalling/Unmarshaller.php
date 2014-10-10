<?php

namespace PAXB\Xml\Marshalling;

interface Unmarshaller
{
    /**
     * @param  string $string
     * @param  string $rootClass
     * @return mixed
     */
    public function unmarshall($string, $rootClass);
}
