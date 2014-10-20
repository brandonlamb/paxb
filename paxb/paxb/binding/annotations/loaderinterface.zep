
namespace PAXB\Binding\Annotations;

use PAXB\Xml\Binding\Metadata\MetadataInterface;

interface LoaderInterface
{
    /**
     * @param \PAXB\Xml\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     */
    public function processMetadata(<MetadataInterface> metadata) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>;
}
