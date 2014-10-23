
namespace PAXB\Binding\Metadata;

interface FactoryInterface
{
    /**
     * @param string $className
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    public function getMetadata(string! className) -> <\PAXB\Binding\Metadata\MetadataInterface>;
}
