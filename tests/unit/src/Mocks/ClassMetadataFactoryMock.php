<?php

namespace PAXB\Tests\Mocks;

use PAXB\Xml\Binding\Metadata\ClassMetadata;
use PAXB\Xml\Binding\Metadata\ClassMetadataFactory;

class ClassMetadataFactoryMock implements ClassMetadataFactory
{
    /*
     * @var ClassMetadata[]
     */
    private $injectedMetadata;

    /*
     * @param ClassMetaData $injectedMetadata ClassMetadata[]
     */
    public function __construct(ClassMetadata $injectedMetadata)
    {
        $this->injectedMetadata = $injectedMetadata;
    }

    /**
     * @param string $className
     * @return ClassMetadata
     */
    public function getClassMetadata($className)
    {
        if (isset($this->injectedMetadata[$className])) {
            return $this->injectedMetadata[$className];
        }

        return null;
    }
}
