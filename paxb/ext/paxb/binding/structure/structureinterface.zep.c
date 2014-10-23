
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PAXB_Binding_Structure_StructureInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Binding\\Structure, StructureInterface, paxb, binding_structure_structureinterface, paxb_binding_structure_structureinterface_method_entry);

	zend_declare_class_constant_long(paxb_binding_structure_structureinterface_ce, SL("GETTER_SOURCE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(paxb_binding_structure_structureinterface_ce, SL("FIELD_SOURCE"), 2 TSRMLS_CC);

	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(PAXB_Binding_Structure_StructureInterface, getName);

/**
 * @return int
 */
ZEPHIR_DOC_METHOD(PAXB_Binding_Structure_StructureInterface, getSource);

/**
 * @param string $name
 */
ZEPHIR_DOC_METHOD(PAXB_Binding_Structure_StructureInterface, setName);

/**
 * @param int $source
 */
ZEPHIR_DOC_METHOD(PAXB_Binding_Structure_StructureInterface, setSource);

