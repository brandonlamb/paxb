<?php

namespace PAXB\Xml\Binding;

use ReflectionProperty;
use Doctrine\Common\Annotations\AnnotationException;
use Doctrine\Common\Annotations\Reader;
use PAXB\Xml\Binding\Annotations\XmlAnnotation;
use PAXB\Xml\Binding\Annotations\XmlAttribute;
use PAXB\Xml\Binding\Annotations\XmlElement;
use PAXB\Xml\Binding\Annotations\XmlElementWrapper;
use PAXB\Xml\Binding\Metadata\Metadata;
use PAXB\Xml\Binding\Structure\Attribute;
use PAXB\Xml\Binding\Structure\Element;

class AnnotationLoader
{
    const ANNOTATIONS_NAMESPACE = 'PAXB\Xml\Binding\Annotations';
    const MODE_EMPTY     = 'DEFAULT';
    const MODE_ELEMENT   = 'ELEMENT';
    const MODE_ATTRIBUTE = 'ATTRIBUTE';
    const MODE_VALUE     = 'VALUE';
    const MODE_TRANSIENT = 'TRANSIENT';

    /**
     * @var Reader
     */
    private $reader;

    /**
     * Annotation loader constructor
     *
     * @param \Doctrine\Common\Annotations\Reader $reader
     */
    public function __construct(Reader $reader)
    {
        $this->reader = $reader;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @return \PAXB\Xml\Binding\Metadata\Metadata
     */
    public function loadClassMetadata(Metadata $metadata)
    {
        $this->processClassAnnotations($metadata);
        #$this->processMethodAnnotations($metadata);
        $this->processPropertyAnnotations($metadata);

        return $metadata;
    }

    /**
     * @param \ReflectionProperty $property
     * @return \PAXB\Xml\Binding\Structure\Element
     */
    public function getDefaultElement(ReflectionProperty $property)
    {
        return new Element($property->getName(), Element::FIELD_SOURCE);
    }

    /**
     * @param \PAXB\Xml\Binding\Structure\Element $element
     * @param \ReflectionProperty $property
     * @return \PAXB\Xml\Binding\Structure\Element
     */
    public function getCurrentElement($element, ReflectionProperty $property)
    {
        null === $element && $element = $this->getDefaultElement($property);
        return $element;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @return \PAXB\Xml\Binding\Metadata\Metadata
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processClassAnnotations(Metadata $metadata)
    {
        $annotations = $this->reader->getClassAnnotations($metadata->getReflection());
        $classTokens = explode('\\', $metadata->getClassName());

        // set default name
        $metadata->setName(end($classTokens));

        foreach ($annotations as &$annotation) {
            $className = get_class($annotation);
            switch ($className) {
                case 'PAXB\Xml\Binding\Annotations\XmlRootElement':
                    // @var \PAXB\Xml\Binding\Annotations\XmlRootElement $annotation
                    !empty($annotation->name) && $metadata->setName($annotation->name);
                    break;

                default:
                    if ($annotation instanceof XmlAnnotation) {
                        throw AnnotationException::semanticalError(
                            $className . ' not expected as class annotation'
                        );
                    }
                    break;
            }
        }

        return $metadata;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @return \PAXB\Xml\Binding\Metadata\Metadata
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processPropertyAnnotations(Metadata $metadata)
    {
#d(__METHOD__, $metadata->getReflection()->getProperties());

        foreach ($metadata->getReflection()->getProperties() as &$property) {
            $element = null;
            $attribute = null;
            $state = self::MODE_EMPTY;

            $annotations = $this->reader->getPropertyAnnotations($property);
#print_r($annotations);

            foreach ($annotations as &$annotation) {
                $className = get_class($annotation);
                switch ($className) {
                    case 'var':
                        d(__METHOD__, __LINE__, $annotation);

                    case 'PAXB\Xml\Binding\Annotations\XmlElement':
                        $state = $this->changeMode($state, self::MODE_ELEMENT);
                        $element = $this->processElementAnnotation(
                            $this->getCurrentElement($element, $property),
                            $property,
                            $annotation
                        );
                        $metadata->addElement($property->getName(), $element);
                        break;

                    case 'PAXB\Xml\Binding\Annotations\XmlElementWrapper':
                        $state = $this->changeMode($state, self::MODE_ELEMENT);
                        $element = $this->processElementWrapperAnnotation(
                            $this->getCurrentElement($element, $property),
                            $property,
                            $annotation
                        );
                        $metadata->addElement($property->getName(), $element);
                        break;

                    case 'PAXB\Xml\Binding\Annotations\XmlPhpCollection':
                        $state = $this->changeMode($state, self::MODE_ELEMENT);
                        $element = $this->getCurrentElement($element, $property);
                        $element->setPhpCollection(true);
                        $metadata->addElement($property->getName(), $element);
                        break;

                    case 'PAXB\Xml\Binding\Annotations\XmlTransient':
                        $state = $this->changeMode($state, self::MODE_TRANSIENT);
                        break;

                    case 'PAXB\Xml\Binding\Annotations\XmlAttribute':
                        $state = $this->changeMode($state, self::MODE_TRANSIENT);
                        $attribute = $this->processAttribute($property, $annotation);
                        $metadata->addAttributes($property->getName(), $attribute);
                        break;

                    case 'PAXB\Xml\Binding\Annotations\XmlValue':
                        $state = $this->changeMode($state, self::MODE_TRANSIENT);
                        $currentValue = $metadata->getValueElement();
                        if (!empty($currentValue)) {
                            throw AnnotationException::semanticalError(
                                'Cannot set more than one field of complex element as XmlValue'
                            );
                        }
                        $metadata->setValueElement($property->getName());
                        break;

                    default:
echo __METHOD__ . ':' . __LINE__ . " - $className\n";
print_r($annotation);
                        if ($annotation instanceof XmlAnnotation) {
                            throw AnnotationException::semanticalError(
                                $className . ' not expected as property annotation'
                            );
                        }
                        break;
                }
            }

            if ($state === self::MODE_EMPTY) {
                $metadata->addElement(
                    $property->getName(),
                    $this->getDefaultElement($property)
                );
            }
        }

        return $metadata;
    }

    /**
     * @param string $actualState
     * @param string $destinationState
     * @return string
     */
    private function changeMode($actualState, $destinationState)
    {
        if ($actualState !== self::MODE_EMPTY) {
            if ($actualState !== self::MODE_ELEMENT || $actualState != $destinationState) {
                throw AnnotationException::semanticalError(
                    'Cannot use simultaneous '. $actualState.', ' . $destinationState. ' annotations '
                );
            }
        }

        return $destinationState;
    }

    /**
     * @param \PAXB\Xml\Binding\Structure\Element $element
     * @param \ReflectionProperty $property
     * @param \PAXB\Xml\Binding\Annotations\XmlElement $annotation
     * @return \PAXB\Xml\Binding\Structure\Element
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processElementAnnotation(Element $element, ReflectionProperty $property, XmlElement $annotation)
    {
        !empty($annotation->name) && $element->setName($annotation->name);

        if (!empty($annotation->type)) {
            if (!class_exists($annotation->type)) {
                throw AnnotationException::semanticalError(
                    'Cannot found defined type: ' . $annotation->type
                );
            }
            $element->setTypeValue($annotation->type);
        }

        return $element;
    }

    /**
     * @param \PAXB\Xml\Binding\Structure\Element $element
     * @param \ReflectionProperty $property
     * @param \PAXB\Xml\Binding\Annotations\XmlElementWrapper $annotation
     * @return \PAXB\Xml\Binding\Structure\Element
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processElementWrapperAnnotation(Element $element, ReflectionProperty $property, XmlElementWrapper $annotation)
    {
        if (empty($annotation->name)) {
            throw AnnotationException::semanticalError(
                'Cannot use XmlElementWrapper without name'
            );
        }

        return $element->setWrapperName($annotation->name);
    }

    /**
     * @param \ReflectionProperty $property
     * @param \PAXB\Xml\Binding\Annotations\XmlAttribute $annotation
     * @return \PAXB\Xml\Binding\Structure\Attribute
     */
    private function processAttribute(ReflectionProperty $property, XmlAttribute $annotation)
    {
        $attribute = new Attribute($property->getName(), Attribute::FIELD_SOURCE);
        !empty($annotation->name) && $attribute->setName($annotation->name);
        return $attribute;
    }
}
