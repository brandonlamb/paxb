
namespace PAXB\Xml\Binding\Metadata;

interface MetadataFactoryInterface
{
    /**
     * @param string $className
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     */
    public function getMetadata(string! className) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>;
}
