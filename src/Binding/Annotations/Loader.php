<?php

namespace PAXB\Binding\Annotations;

use ReflectionProperty;

use PAXB\Binding\Annotations\AbstractLoader;
use PAXB\Binding\Annotations\Exception as AnnotationException;
use PAXB\Xml\Binding\Annotations\XmlAnnotation;
use PAXB\Xml\Binding\Annotations\XmlAttribute;
use PAXB\Xml\Binding\Annotations\XmlElement;
use PAXB\Xml\Binding\Annotations\XmlElementWrapper;
use PAXB\Binding\Metadata\MetadataInterface;
use PAXB\Xml\Binding\Structure\Attribute;
use PAXB\Xml\Binding\Structure\Element;

class Loader extends AbstractLoader
{
    const MODE_EMPTY     = 'DEFAULT';
    const MODE_ELEMENT   = 'ELEMENT';
    const MODE_ATTRIBUTE = 'ATTRIBUTE';
    const MODE_VALUE     = 'VALUE';
    const MODE_TRANSIENT = 'TRANSIENT';

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
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    protected function processClassAnnotations(MetadataInterface $metadata)
    {
#d(__METHOD__, $metadata->getReflectionClass());

        $annotations = $this->reader->getClassAnnotations($metadata->getReflectionClass());
        $classTokens = explode('\\', $metadata->getClassName());

        // set default name
        $metadata->setName(end($classTokens));

        foreach ($annotations as &$annotation) {
            if ($annotation instanceof FilterAnnotation) {
                #$this->filterLoader->processClassAnnotation($annotation, $metadata);
                $metadata->addPropertyRule($property->getName(), $annotation);
            }

            if ($annotation instanceof XmlAnnotation) {
                $this->xmlLoader->processClassAnnotation($annotation, $metadata);
            }
        }

        return $metadata;
    }

    /**
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    protected function processMethodAnnotations(MetadataInterface $metadata)
    {
        foreach ($metadata->getReflectionClass()->getMethods() as &$method) {
            $element = null;
            $attribute = null;
            $state = self::MODE_EMPTY;

            $annotations = $this->reader->getMethodAnnotations($method);

            foreach ($annotations as &$annotation) {
                if ($annotation instanceof FilterAnnotation) {
                    #$this->filterLoader->processMethodAnnotation($annotation, $metadata);
                    $metadata->addPropertyRule($property->getName(), $annotation);
                }

                if ($annotation instanceof XmlAnnotation) {
                    $this->xmlLoader->processMethodAnnotation($annotation, $metadata);
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
     * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
     * @return \PAXB\Binding\Metadata\MetadataInterface
     * @throws \Doctrine\Common\Annotations\AnnotationException
     */
    protected function processPropertyAnnotations(MetadataInterface $metadata)
    {
#d(__METHOD__, $metadata->getReflectionClass()->getProperties());

        foreach ($metadata->getReflectionClass()->getProperties() as &$property) {
            $element = null;
            $attribute = null;
            $state = self::MODE_EMPTY;

            $annotations = $this->reader->getPropertyAnnotations($property);
#print_r($annotations);

            foreach ($annotations as &$annotation) {
                if ($annotation instanceof FilterAnnotation) {
                    #$this->filterLoader->processPropertyAnnotation($annotation, $metadata);
                    $metadata->addPropertyRule($property->getName(), $annotation);
                }

                if ($annotation instanceof XmlAnnotation) {
                    $this->xmlLoader->processPropertyAnnotation($annotation, $metadata);
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
    protected function changeMode($actualState, $destinationState)
    {
        if ($actualState !== self::MODE_EMPTY) {
            if ($actualState !== self::MODE_ELEMENT || $actualState != $destinationState) {
                throw new AnnotationException(
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
    protected function processElementAnnotation(Element $element, ReflectionProperty $property, XmlElement $annotation)
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
    protected function processElementWrapperAnnotation(Element $element, ReflectionProperty $property, XmlElementWrapper $annotation)
    {
        if (empty($annotation->name)) {
            throw new AnnotationException(
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
    protected function processAttribute(ReflectionProperty $property, XmlAttribute $annotation)
    {
        $attribute = new Attribute($property->getName(), Attribute::FIELD_SOURCE);
        !empty($annotation->name) && $attribute->setName($annotation->name);
        return $attribute;
    }
}
