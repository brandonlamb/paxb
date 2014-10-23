
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_LoaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Binding\\Annotations, LoaderInterface, paxb, binding_annotations_loaderinterface, paxb_binding_annotations_loaderinterface_method_entry);

	return SUCCESS;

}

/**
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 */
ZEPHIR_DOC_METHOD(PAXB_Binding_Annotations_LoaderInterface, processMetadata);

