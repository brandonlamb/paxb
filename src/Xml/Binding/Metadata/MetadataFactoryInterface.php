<?php

namespace PAXB\Xml\Binding\Metadata;

interface MetadataFactoryInterface
{
    /**
     * @param string $className
     * @return \PAXB\Xml\Binding\Metadata\Metadata
     */
    public function getClassMetadata($className);
}
