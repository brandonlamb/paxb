<?php

namespace PAXB;

use Doctrine\Common\Annotations\AnnotationRegistry;
use Doctrine\Common\Annotations\SimpleAnnotationReader;
use Doctrine\Common\Annotations\CachedReader;
use Doctrine\Common\Cache\ArrayCache;
use Doctrine\Common\Cache\ApcCache;
use Doctrine\Common\Cache\Cache;

use PAXB\Binding\Annotations\Loader as AnnotationLoader;
use PAXB\Binding\Annotations\Loader\XmlLoader;
use PAXB\Binding\Metadata\Container;
use PAXB\Binding\Metadata\Factory as MetadataFactory;
use PAXB\Xml\Marshall\DOMDocumentMarshaller;
use PAXB\Xml\Marshall\Marshaller;
use PAXB\Xml\Unmarshall\DOMDocumentUnmarshaller;
use PAXB\Xml\Unmarshall\Unmarshaller;

/**
 * This class is using only for demo purposes, i highly recommend using DI (ie. Symfony2 container)
 */
class Setup
{
    /**
     * @var \PAXB\Binding\Metadata\FactoryInterface
     */
    private static $metadataFactory;

    /**
     * @var Marshaller
     */
    private static $marshaller;

    /**
     * @var Unmarshaller
     */
    private static $unmarshaller;

    /**
     * @return Marshaller
     */
    public static function getMarshaller()
    {
        if (self::$marshaller == null) {
            self::$marshaller = new DOMDocumentMarshaller(
                self::getMetadataFactory(),
                true
            );
        }

        return self::$marshaller;
    }

    /**
     * @return Unmarshaller
     */
    public static function getUnmarshaller()
    {
        if (self::$unmarshaller == null) {
            self::$unmarshaller = new DOMDocumentUnmarshaller(
                self::getMetadataFactory()
            );
        }

        return self::$unmarshaller;
    }

    /**
     * @return \PAXB\Binding\Metadata\MetadataFactory
     */
    public static function getMetadataFactory()
    {
        if (self::$metadataFactory == null) {
            #$cache = new ApcCache;
            $cache = new ArrayCache;

            // Register annotation namespaces
            $reader = new SimpleAnnotationReader;
            $reader->addNamespace('PAXB\Binding\Annotations\Filter');
            $reader->addNamespace('PAXB\Binding\Annotations\Xml');

            AnnotationRegistry::registerFile(__DIR__ . '/Binding/Annotations/Filter/PAXBAnnotations.php');
            AnnotationRegistry::registerFile(__DIR__ . '/Binding/Annotations/Xml/PAXBAnnotations.php');

            // foreach (glob(__DIR__ . '/Binding/Annotations/Filter/*.php') as $annotationFile) {
            //     AnnotationRegistry::registerFile($annotationFile);
            // }
            // foreach (glob(__DIR__ . '/Binding/Annotations/Xml/*.php') as $annotationFile) {
            //     AnnotationRegistry::registerFile($annotationFile);
            // }

            self::$metadataFactory = new MetadataFactory(
                new AnnotationLoader(
                    new CachedReader($reader, $cache),
                    new XmlLoader()
                ),
                new Container(),
                $cache
            );
        }

        return self::$metadataFactory;
    }
}
