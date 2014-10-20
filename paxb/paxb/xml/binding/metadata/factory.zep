
namespace PAXB\Xml\Binding\Metadata;

//use Doctrine\Common\Cache\Cache;
use PAXB\Xml\Binding\AnnotationLoader;

class Factory implements FactoryInterface
{
    const CACHE_PREFIX = "PAXB_MD:";

    /**
     * @var \PAXB\Xml\Binding\AnnotationLoader
     */
    private loader;

    /**
     * @var \Doctrine\Common\Cache\Cache
     */
    private cache;

    /**
     * @param \PAXB\Xml\Binding\AnnotationLoader $loader
     * @param \Doctrine\Common\Cache\Cache $cache
     * @TODO Update type hint
     */
    public function __construct(var loader, var cache = null)
    {
        let this->loader = loader;
        let this->cache = cache;
    }

    /**
     * @param string $className
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     */
    public function getMetadata(string! className) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>
    {
        var cacheKey, metadata;

echo __METHOD__ . ": " . className . "\n";

        let cacheKey = self::CACHE_PREFIX . md5(className);

        // If cache is an object, try fetching metadata from cache
        if typeof this->cache == "object" {
            let metadata = this->cache->$fetch(cacheKey);
            if typeof metadata == "object" {
                if (metadata instanceof MetadataInterface) {
                    return metadata;
                }
            }
        }

        // No cached metadata found, create new instance
        let metadata = new Metadata(className);
        this->loader->processMetadata(metadata);

        // If cache is set, save the metadata to cache
        if typeof this->cache == "object" {
            this->cache->save(cacheKey, metadata);
        }

        return metadata;
    }
}
