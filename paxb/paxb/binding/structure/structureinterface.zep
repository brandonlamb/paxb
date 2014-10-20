
namespace PAXB\Binding\Structure;

interface StructureInterface
{
    const GETTER_SOURCE = 1;
    const FIELD_SOURCE  = 2;

    /**
     * @return string
     */
    public function getName() -> string;

    /**
     * @return int
     */
    public function getSource() -> int;

    /**
     * @param string $name
     */
    public function setName(string! name) -> <StructureInterface>;

    /**
     * @param int $source
     */
    public function setSource(int source) -> <StructureInterface>;
}
