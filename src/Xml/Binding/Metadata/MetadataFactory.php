<?php

namespace PAXB\Xml\Binding\Metadata;

use Doctrine\Common\Cache\Cache;
use PAXB\Xml\Binding\AnnotationLoader;

class MetadataFactory implements MetadataFactoryInterface
{
    const CACHE_PREFIX = 'PAXB_MD:';

    /**
     * @var \PAXB\Xml\Binding\AnnotationLoader
     */
    private $loader;

    /**
     * @var \Doctrine\Common\Cache\Cache
     */
    private $cache;

    /**
     * @param \PAXB\Xml\Binding\AnnotationLoader $loader
     * @param \Doctrine\Common\Cache\Cache $cache
     */
    public function __construct($loader, Cache $cache = null)
    {
        $this->loader = $loader;
        $this->cache = $cache;
    }

    /**
     * @param string $className
     * @return \PAXB\Xml\Binding\Metadata\Metadata
     */
    public function getClassMetadata($className)
    {
        $cacheKey = self::CACHE_PREFIX . md5($className);
        $metadata = ($this->cache !== null) ? $this->cache->fetch($cacheKey) : null;

        if (!($metadata instanceof Metadata)) {
            $metadata = new Metadata($className);
            $this->loader->loadClassMetadata($metadata);
            $this->cache !== null && $this->cache->save($cacheKey, $metadata);
        }

        return $metadata;
    }
}
