
namespace PAXB\Binding\Metadata;

use PAXB\Filter\Annotations\AnnotationsInterface;
use PAXB\Filter\Rule\RuleInterface;
use PAXB\Xml\Binding\Structure\Attribute;
use PAXB\Xml\Binding\Structure\Element;
use ReflectionClass;
use RuntimeException;

class Metadata implements MetadataInterface
{
    const RUNTIME_TYPE   = 1;
    const DEFINED_TYPE   = 2;

    /**
     * @var string
     */
    protected className;

    /**
     * @var string
     */
    protected name;

    /**
     * @var array
     */
    protected attributes;

    /**
     * @var Element[]
     */
    protected elements;

    /**
     * @var string
     */
    protected valueElement;

    /**
     * Properties that contain filtering rules
     * @var array
     */
    protected filteredProperties;

    /**
     * @var \ReflectionClass
     */
    protected reflection;

    /**
     * @param string $className
     */
    public function __construct(string! className)
    {
        if className === "" {
            throw new RuntimeException(__METHOD__ . ": must pass non-empty className");
        }

        let this->className = className;
        let this->name = "";
        let this->attributes = [];
        let this->elements = [];
        let this->valueElement = "";
        let this->filteredProperties = [];
    }

    /**
     * Get name of class represented in this Metadata object
     *
     * @return string
     */
    public function getClassName() -> string
    {
        return this->className;
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @return array
     */
    public function getAttributes() -> array
    {
        return this->attributes;
    }

    /**
     * @return \PAXB\Binding\Metadata\Element[]
     */
    public function getElements() -> array
    {
        return this->elements;
    }

    /**
     * @return string
     */
    public function getValueElement() -> string
    {
        return this->valueElement;
    }

    /**
     * {@inheritDoc}
     */
    public function getFilteredProperties() -> array
    {
        return array_keys(this->filteredProperties);
    }

    /**
     * Returns a ReflectionClass instance for this class
     *
     * @return \ReflectionClass
     */
    public function getReflectionClass() -> <\ReflectionClass>
    {
        if typeof this->reflection == "null" {
            let this->reflection = new ReflectionClass(this->getClassName());
        }

        return this->reflection;
    }

    /**
     * {@inheritDoc}
     */
    public function getPropertyRules(string! property) -> array | null
    {
        if !isset this->filteredProperties[property] {
            return null;
        }

        return this->filteredProperties[property]["rules"];
    }

    /**
     * {@inheritDoc}
     */
    public function addPropertyRule(string! property, <AnnotationsInterface> rule) -> <\PAXB\Binding\MetadataInterface>
    {
        if !isset this->filteredProperties[property] {
            let this->filteredProperties[property] = ["rules": []];
        }

        let this->filteredProperties[property]["rules"][] = rule;

        return this;
    }

    /**
     * {@inheritDoc}
     */
    public function mergeRules(<MetadataInterface> metadata) -> <\PAXB\Binding\MetadataInterface>
    {
        var property, rule;

        for property in metadata->getFilteredProperties() {
            for rule in metadata->getPropertyRules(property) {
                this->addPropertyRule(property, clone rule);
            }
        }

        return this;
    }

    /**
     * @param string $fieldName
     * @param \PAXB\Xml\Binding\Structure\Attribute $attribute
     * @return \PAXB\Binding\MetadataInterface
     */
    public function addAttributes(string! fieldName, <Attribute> attribute) -> <\PAXB\Binding\MetadataInterface>
    {
        let this->attributes[fieldName] = attribute;
        return this;
    }

    /**
     * @param string $fieldName
     * @param \PAXB\Xml\Binding\Structure\Element $element
     * @return \PAXB\Binding\MetadataInterface
     */
    public function addElement(string! fieldName, <Element> element) -> <\PAXB\Binding\MetadataInterface>
    {
        let this->elements[fieldName] = element;
        return this;
    }

    /**
     * @param string $name
     * @return \PAXB\Binding\MetadataInterface
     */
    public function setName(string! name) -> <\PAXB\Binding\MetadataInterface>
    {
        let this->name = trim(name);
        return this;
    }

    /**
     * @param string $valueElement
     * @return \PAXB\Binding\MetadataInterface
     */
    public function setValueElement(string! valueElement) -> <\PAXB\Binding\MetadataInterface>
    {
        let this->valueElement = trim(valueElement);
        return this;
    }
}
