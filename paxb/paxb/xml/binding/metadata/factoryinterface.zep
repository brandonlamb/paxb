
namespace PAXB\Xml\Binding\Metadata;

interface FactoryInterface
{
    /**
     * @param string $className
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     */
    public function getMetadata(string! className) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>;
}
