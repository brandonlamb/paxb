<?php

namespace PAXB\Xml\Marshalling;

interface Marshaller
{
    /**
     * @param  mixed  $object
     * @param  bool   $format
     * @return string
     */
    public function marshall($object, $format=false);
}
