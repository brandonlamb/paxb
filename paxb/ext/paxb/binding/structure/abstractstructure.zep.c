
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PAXB_Binding_Structure_AbstractStructure) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Binding\\Structure, AbstractStructure, paxb, binding_structure_abstractstructure, paxb_binding_structure_abstractstructure_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(paxb_binding_structure_abstractstructure_ce, SL("name"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(paxb_binding_structure_abstractstructure_ce, SL("source"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(paxb_binding_structure_abstractstructure_ce TSRMLS_CC, 1, paxb_binding_structure_structureinterface_ce);
	return SUCCESS;

}

/**
 * @return string
 */
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * @return int
 */
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, getSource) {


	RETURN_MEMBER(this_ptr, "source");

}

/**
 * @param string $name
 */
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param int $source
 */
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, setSource) {

	zval *source_param = NULL, *_0;
	int source;

	zephir_fetch_params(0, 1, 0, &source_param);

	source = zephir_get_intval(source_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, source);
	zephir_update_property_this(this_ptr, SL("source"), _0 TSRMLS_CC);
	RETURN_THISW();

}

