
namespace PAXB\Xml\Binding\Structure;

use PAXB\Binding\Structure\Base;

class Attribute extends Base
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
