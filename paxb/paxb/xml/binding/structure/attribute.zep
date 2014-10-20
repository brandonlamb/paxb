
namespace PAXB\Xml\Binding\Structure;

use PAXB\Binding\Structure\AbstractStructure;

class Attribute extends AbstractStructure
{
    /**
     * Constructor
     *
     * @param string name
     * @param int source
     */
    public function __construct(string! name, int source)
    {
        let this->name = name;
        let this->source = source;
    }
}
