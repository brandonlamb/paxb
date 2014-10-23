
namespace PAXB\Xml\Binding\Structure;

use PAXB\Binding\Structure\AbstractStructure;
use PAXB\Binding\Metadata\Metadata;

class Element extends AbstractStructure
{
    /**
     * @var int
     */
    private type = 0 { get };

    /**
     * @var string
     */
    private typeValue = "" { get };

    /**
     * @var string
     */
    private wrapperName = "" { get };

    /**
     * @var bool
     */
    private phpCollection = false { get };

    /**
     * Constructor
     *
     * @param string name
     * @param int source
     * @param int type
     * @param string typeValue
     * @param string wrapperName
     * @param bool phpCollection
     */
    public function __construct(string! name, int source, int type = null, string! typeValue = "", string! wrapperName = null, boolean phpCollection = false)
    {
        let this->name = name;
        //let this->type = (typeof type == "null") ? Metadata::RUNTIME_TYPE : type;
        let this->type = (typeof type == "null") ? 1 : type;
        let this->typeValue = typeValue;
        let this->source = source;
        let this->wrapperName = wrapperName;
        let this->phpCollection = phpCollection;
    }

    /**
     * @param string $wrapperName
     * @return Element
     */
    public function setWrapperName(string! wrapperName) -> <Element>
    {
        let this->wrapperName = wrapperName;
        return this;
    }

    /**
     * @param string $typeValue
     * @return Element
     */
    public function setTypeValue(string! typeValue) -> <Element>
    {
        //let this->type = Metadata::DEFINED_TYPE;
        let this->type = 2;
        let this->typeValue = typeValue;
        return this;
    }

    /**
     * @param boolean $phpCollection
     * @return Element
     */
    public function setPhpCollection(boolean phpCollection) -> <Element>
    {
        let this->phpCollection = phpCollection;
        return this;
    }
}
