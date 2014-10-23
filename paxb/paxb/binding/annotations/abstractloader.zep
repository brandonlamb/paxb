
namespace PAXB\Binding\Annotations;

//use Doctrine\Common\Annotations\Reader;
use PAXB\Binding\Metadata\MetadataInterface;

abstract class AbstractLoader
{
    /**
     * @var \Doctrine\Common\Annotations\Reader
     */
    protected reader;

    /**
     * @var \PAXB\Binding\Annotations\LoaderInterface
     */
    protected xmlLoader;

    /**
     * Annotation loader constructor
     *
     * @param \Doctrine\Common\Annotations\Reader $reader
     * @param array $namespaces
     * @TODO Better way to load annotations?
     */
    public function __construct(var reader, var xmlLoader)
    {
        let this->reader = reader;
        let this->xmlLoader = xmlLoader;
    }

    /**
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     */
    public function processMetadata(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>
    {
        this->processClassAnnotations(metadata);
        this->processMethodAnnotations(metadata);
        this->processPropertyAnnotations(metadata);

        return metadata;
    }

    /**
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    abstract protected function processClassAnnotations(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>;

    /**
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    abstract protected function processMethodAnnotations(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>;

    /**
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    abstract protected function processPropertyAnnotations(<MetadataInterface> metadata) -> <\PAXB\Binding\Metadata\MetadataInterface>;
}
