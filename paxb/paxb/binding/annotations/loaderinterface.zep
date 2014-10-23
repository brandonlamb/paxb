
namespace PAXB\Binding\Annotations;

use PAXB\Binding\Metadata\MetadataInterface;

interface LoaderInterface
{
    /**
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    public function processMetadata(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>;
}
