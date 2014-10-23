
namespace PAXB\Binding\Metadata;

class Container
{
    /**
     * @var array
     */
    protected storage;

    /**
     * Constructor
     *
     * @param array Metadata[]
     */
    public function __construct(array storage = [])
    {
        let this->storage = storage;
    }

    /**
     * Add a metadata object by classname
     *
     * @param string key
     * @param \PAXB\Binding\Metadata\MetadataInterface metadata
     * @return \PAXB\Binding\Metadata\Container
     */
    public function set(string! key, <MetadataInterface> metadata) -> <Container>
    {
        let this->storage[key] = metadata;
        return this;
    }

    /**
     * Get a metadata object from container if it exists
     *
     * @param string key
     * return \PAXB\Binding\Metadata\MetadataInterface
     */
    public function get(string! key) -> <\PAXB\Binding\Metadata\MetadataInterface>
    {
        var metadata;
        if fetch metadata, this->storage[key] {
            return metadata;
        }
        throw new Exception(__METHOD__ . " - Container does not have " . key);
    }

    /**
     * Check if container has metadata for a class
     *
     * @param string key
     * return boolean
     */
    public function has(string! key) -> boolean
    {
        var metadata;
        if fetch metadata, this->storage[key] {
            return true;
        }
        return false;
    }
}
