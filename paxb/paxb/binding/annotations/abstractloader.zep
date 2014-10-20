
namespace PAXB\Binding\Annotations;

//use Doctrine\Common\Annotations\Reader;
use PAXB\Xml\Binding\Metadata\MetadataInterface;

abstract class AbstractLoader
{
    /**
     * @var \Doctrine\Common\Annotations\Reader
     */
    protected reader;

    /**
     * Annotation loader constructor
     *
     * @param \Doctrine\Common\Annotations\Reader $reader
     * @param array $namespaces
     * @TODO Better way to load annotations?
     */
    public function __construct(var reader, array namespaces = [])
    {
        let this->reader = reader;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     */
    public function processMetadata(<MetadataInterface> metadata) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>
    {
        this->processClassAnnotations(metadata);
        this->processMethodAnnotations(metadata);
        this->processPropertyAnnotations(metadata);

        return metadata;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    abstract protected function processClassAnnotations(<MetadataInterface> metadata) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>;

    /**
     * @param \PAXB\Xml\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    abstract protected function processMethodAnnotations(<MetadataInterface> metadata) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>;

    /**
     * @param \PAXB\Xml\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    abstract protected function processPropertyAnnotations(<MetadataInterface> metadata) -> <\PAXB\Xml\Binding\Metadata\MetadataInterface>;
}
