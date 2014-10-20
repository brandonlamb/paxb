
namespace PAXB\Binding\Structure;

abstract class AbstractStructure implements StructureInterface
{
    protected name = "";
    protected source = 0;

    /**
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @return int
     */
    public function getSource() -> int
    {
        return this->source;
    }

    /**
     * @param string $name
     */
    public function setName(string! name) -> <StructureInterface>
    {
        let this->name = name;
        return this;
    }

    /**
     * @param int $source
     */
    public function setSource(int source) -> <StructureInterface>
    {
        let this->source = source;
        return this;
    }
}
