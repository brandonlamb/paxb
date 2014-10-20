
namespace PAXB\Binding\Structure;

class Base
{
    const GETTER_SOURCE = 1;
    const FIELD_SOURCE  = 2;

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
    public function setName(string! name) -> <Base>
    {
        let this->name = name;
        return this;
    }

    /**
     * @param int $source
     */
    public function setSource(int source) -> <Base>
    {
        let this->source = source;
        return this;
    }
}
