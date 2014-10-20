<?php

namespace PAXB;

use Doctrine\Common\Annotations\AnnotationRegistry;
use Doctrine\Common\Annotations\SimpleAnnotationReader;
use Doctrine\Common\Annotations\CachedReader;
use Doctrine\Common\Cache\ArrayCache;
use Doctrine\Common\Cache\ApcCache;
use Doctrine\Common\Cache\Cache;

use PAXB\Xml\Binding\AnnotationLoader;
use PAXB\Xml\Binding\Metadata\Factory as MetadataFactory;
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
     * @var \PAXB\Xml\Binding\Metadata\MetadataFactoryInterface
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
     * @return \PAXB\Xml\Binding\Metadata\MetadataFactory
     */
    public static function getMetadataFactory()
    {
        if (self::$metadataFactory == null) {
            #$cache = new ApcCache;
            $cache = new ArrayCache;

            // Register annotation namespaces
            $reader = new SimpleAnnotationReader;
            $reader->addNamespace('PAXB\Xml\Binding\Annotations');
            foreach (glob(__DIR__ . '/Xml/Binding/Annotations/*.php') as $annotationFile) {
                AnnotationRegistry::registerFile($annotationFile);
            }

            self::$metadataFactory = new MetadataFactory(
                new AnnotationLoader(new CachedReader($reader, $cache)),
                $cache
            );
        }

        return self::$metadataFactory;
    }

    /**
     * @param SimpleAnnotationReader $reader
     */
    private static function loadAnnotationFiles(SimpleAnnotationReader $reader)
    {
        $reader->addNamespace(AnnotationLoader::ANNOTATIONS_NAMESPACE);
        foreach (glob(__DIR__ . '/Xml/Binding/Annotations/*.php') as $annotationFile) {
            AnnotationRegistry::registerFile($annotationFile);
        }
    }
}
