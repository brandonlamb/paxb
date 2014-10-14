<?php

namespace PAXB\Xml\Binding;

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

    public function __construct(Reader $reader)
    {
        $this->reader = $reader;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     */
    public function loadClassMetadata(Metadata $metadata)
    {
        $metadata = $this->processClassAnnotations($metadata);
        $metadata = $this->processFieldsMetadata($metadata);

        return $metadata;
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

        if (is_array($annotations)) {
            foreach ($annotations as &$annotation) {
                switch (get_class($annotation)) {
                    case 'PAXB\Xml\Binding\Annotations\XmlElement':
                        // @var \PAXB\Xml\Binding\Annotations\XmlElement $annotation
                        !empty($annotation->name) && $metadata->setName($annotation->name);
                        break;

                    default:
                        if ($annotation instanceof XmlAnnotation) {
                            throw AnnotationException::semanticalError(
                                get_class($annotation) . ' not expected as class annotation'
                            );
                        }
                        break;
                }
            }
        }

        return $metadata;
    }

    /**
     * @param \PAXB\Xml\Binding\Metadata\Metadata $metadata
     * @return \PAXB\Xml\Binding\Metadata\Metadata
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processFieldsMetadata(Metadata $metadata)
    {
#d(__METHOD__, $metadata->getReflection()->getProperties());

        foreach ($metadata->getReflection()->getProperties() as &$property) {
            $element = null;
            $attribute = null;
            $state = self::MODE_EMPTY;

            $annotations = $this->reader->getPropertyAnnotations($property);
print_r($annotations);

            if (is_array($annotations)) {
                foreach ($annotations as &$annotation) {

                    switch (get_class($annotation)) {
                        case 'var':
                            d(__METHOD__, __LINE__, $annotation);

                        case 'PAXB\Xml\Binding\Annotations\XmlElement':
                            $state = $this->changeMode($state, self::MODE_ELEMENT);
                            $element = $this->processElementAnnotation($element, $property, $annotation);
                            $metadata->addElement($property->getName(), $element);
                            break;

                        case 'PAXB\Xml\Binding\Annotations\XmlElementWrapper':
                            $state = $this->changeMode($state, self::MODE_ELEMENT);
                            $element = $this->processElementWrapperAnnotation($annotation, $element, $property);
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
                            if ($annotation instanceof XmlAnnotation) {
                                throw AnnotationException::semanticalError(
                                    get_class($annotation) . ' not expected as property annotation'
                                );
                            }
                            break;
                    }
                }
            }

            if ($state === self::MODE_EMPTY) {
                $metadata->addElement($property->getName(), $this->getDefaultElement($property));
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
     * @param \ReflectionProperty $property
     * @return Element
     */
    public function getDefaultElement($property)
    {
        return new Element($property->getName(), Element::FIELD_SOURCE);
    }

    /**
     * @param Element $element
     * @param \ReflectionProperty $property
     * @return Element
     */
    public function getCurrentElement($element, $property)
    {
        if (is_null($element)) {
            $element = $this->getDefaultElement($property);
        }

        return $element;
    }

    /**
     * @param Element $element
     * @param \ReflectionProperty $property
     * @param XmlElement $annotation
     * @return Element
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processElementAnnotation($element, $property, $annotation)
    {
        $element = $this->getCurrentElement($element, $property);

        if (!empty($annotation->name)) {
            $element->setName($annotation->name);
        }

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
     * @param XmlElementWrapper $annotation
     * @param Element $element
     * @param \ReflectionProperty $property
     * @return Element
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    private function processElementWrapperAnnotation($annotation, $element, $property)
    {
        if (empty($annotation->name)) {
            throw AnnotationException::semanticalError(
                'Cannot use XmlElementWrapper without name'
            );
        }

        $element = $this->getCurrentElement($element, $property);
        $element->setWrapperName($annotation->name);

        return $element;
    }

    /**
     * @param \ReflectionProperty $property
     * @param XmlAttribute $annotation
     * @return Attribute
     */
    private function processAttribute($property, $annotation)
    {
        $attribute = new Attribute($property->getName(), Attribute::FIELD_SOURCE);
        if (!empty($annotation->name)) {
            $attribute->setName($annotation->name);
        }

        return $attribute;
    }
}
