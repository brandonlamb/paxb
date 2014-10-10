<?php

namespace PAXB\Tests\Xml\Binding\Metadata;

use PAXB\Xml\Binding\Metadata\BaseClassMetadataFactory;
use PHPUnit_Framework_TestCase;

/**
 * @coversDefaultClass \PAXB\Xml\Binding\BaseClassMetadataFactory
 * @covers ::__construct
 */
class BaseClassMetadataFactoryTest extends PHPUnit_Framework_TestCase
{
    /**
     * @covers ::getClassMetadata
     */
    public function testShouldReturnInstanceOfMetadata() {
        $baseFactory = new BaseClassMetadataFactory($this->getAnnotationLoaderMock());
        $classMetadata = $baseFactory->getClassMetadata('\PAXB\Tests\Mocks\EmptyEntity');

        $this->assertInstanceOf('\PAXB\Xml\Binding\Metadata\ClassMetadata', $classMetadata);
    }

    /**
     * @covers ::getClassMetadata
     */
    public function testShouldInvokeAnnotationLoader() {
        $loader = $this->getAnnotationLoaderMock();

        $loader->expects($this->once())->method('loadClassMetadata');
        $baseFactory = new BaseClassMetadataFactory($loader);

        $baseFactory->getClassMetadata('\PAXB\Tests\Mocks\EmptyEntity');
    }

    /**
     * @return \PHPUnit_Framework_MockObject_MockObject
     */
    public function getAnnotationLoaderMock()
    {
        $loader = $this->getMockBuilder('\PAXB\Xml\Binding\AnnotationLoader')
            ->disableOriginalConstructor()
            ->getMock();
        return $loader;
    }
}
