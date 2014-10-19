
namespace PAXB\Xml\Binding\Metadata;

//use Doctrine\Common\Cache\Cache;
use PAXB\Xml\Binding\AnnotationLoader;

class MetadataFactory implements MetadataFactoryInterface
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

        let cacheKey = self::CACHE_PREFIX . md5(className);

        if typeof this->cache == "null" {
            let metdata = null;
        } else {
            let metadata = this->cache->$fetch(cacheKey);
        }

        if !(metadata instanceof MetadataInterface) {
            let metadata = new Metadata(className);
            this->loader->loadClassMetadata(metadata);

            if typeof this->cache != "null" {
                this->cache->save(cacheKey, metadata);
            }
        }

        return metadata;
    }
}
