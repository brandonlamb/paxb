
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface for methods required by a Metadata class
 */
ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Metadata_MetadataInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Xml\\Binding\\Metadata, MetadataInterface, paxb, xml_binding_metadata_metadatainterface, paxb_xml_binding_metadata_metadatainterface_method_entry);

	return SUCCESS;

}

/**
 * Retrieve a list of the object's properties that have filters attached
 * to them
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_MetadataInterface, getFilteredProperties);

/**
 * Adds a new rule to a property
 *
 * @param string $property
 * @param AnnotationsInterface $rule
 * @return MetadataInterface
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_MetadataInterface, addPropertyRule);

/**
 * Retrieve s list of filtering rules attached to a property
 *
 * @param string $property
 * @return array
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_MetadataInterface, getPropertyRules);

/**
 * Merges rules from another metadata object into this one
 *
 * @param MetadataInterface $metadata
 * @return MetadataInterface
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_MetadataInterface, mergeRules);

/**
 * Get name of class represented in this Metadata object
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_MetadataInterface, getClassName);

/**
 * Returns a ReflectionClass instance for this class.
 *
 * @return ReflectionClass
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_MetadataInterface, getReflectionClass);

