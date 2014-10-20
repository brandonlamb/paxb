
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Metadata_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Xml\\Binding\\Metadata, FactoryInterface, paxb, xml_binding_metadata_factoryinterface, paxb_xml_binding_metadata_factoryinterface_method_entry);

	return SUCCESS;

}

/**
 * @param string $className
 * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
 */
ZEPHIR_DOC_METHOD(PAXB_Xml_Binding_Metadata_FactoryInterface, getMetadata);

