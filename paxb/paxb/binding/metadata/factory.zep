
namespace PAXB\Binding\Metadata;

//use Doctrine\Common\Cache\Cache;
use PAXB\Binding\Annotations\Loader;
use PAXB\Binding\Metadata\Container;

class Factory implements FactoryInterface
{
    const CACHE_PREFIX = "PAXB_MD:";

    /**
     * @var \PAXB\Binding\Annotations\Loader
     */
    private loader;

    /**
     * @var \PAXB\Binding\Metadata\Container
     */
    private container;

    /**
     * @var \Doctrine\Common\Cache\Cache
     */
    private cache;

    /**
     * @param \PAXB\Binding\Annotations\Loader $loader
     * @param \Doctrine\Common\Cache\Cache $cache
     * @TODO Update type hint
     */
    public function __construct(var loader, <Container> container, var cache = null)
    {
        let this->loader = loader;
        let this->container = container;
        let this->cache = cache;
    }

    /**
     * @param string $className
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    public function getMetadata(string! className) -> <\PAXB\Binding\Metadata\MetadataInterface>
    {
        var cacheKey, metadata;

echo __METHOD__ . ": " . className . "\n";

        // If metadata container has already loaded metadata, just return it
        if this->container->has(className) === true {
            return this->container->get(className);
        }

        let cacheKey = self::CACHE_PREFIX . md5(className);

        // If cache is an object, try fetching metadata from cache
        if typeof this->cache == "object" {
            let metadata = this->cache->$fetch(cacheKey);
            if typeof metadata == "object" {
                if (metadata instanceof MetadataInterface) {
                    this->container->set(className, metadata);
                    return metadata;
                }
            }
        }

        let metadata = this->parseMetadata(className);
        this->container->set(className, metadata);
        return metadata;
    }

    /**
     * @param string $className
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    protected function parseMetadata(string! className) -> <\PAXB\Binding\Metadata\MetadataInterface>
    {
        // No cached metadata found, create new instance
        let metadata = new Metadata(className);

        // Load up parent and interfaces
        this->loadParentMetadata(metadata);
        this->loadInterfaceMetadata(metadata);

        // Load Annotations from Reader
        this->loader->processMetadata(metadata);

        // If cache is set, save the metadata to cache
        if typeof this->cache == "object" {
            this->cache->save(cacheKey, metadata);
        }

        return metadata;
    }

    /**
     * Checks if the class being parsed has a parent and cascades parsing
     * to its parent
     *
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    protected function loadParentMetadata(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>
    {
        var parentClass;

        let parent = metadata->getReflectionClass()->getParentClass();

        if typeof parentClass == "object" {
            metadata->mergeRules(this->getMetadata(parentClass->getName()));
        }

        return metadata;
    }

    /**
     * Checks if the object has interfaces and cascades parsing of annotatiosn
     * to all the interfaces
     *
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    protected function loadInterfaceMetadata(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>
    {
        var interfaces, $interface;

        let interfaces = metadata->getReflectionClass()->getInterfaces();
        for $interface in interfaces {
            metadata->mergeRules(this->getMetadata($interface->getName()));
        }

        return metadata;
    }
}
