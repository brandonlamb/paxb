
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Structure_Attribute) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Xml\\Binding\\Structure, Attribute, paxb, xml_binding_structure_attribute, paxb_binding_structure_abstractstructure_ce, paxb_xml_binding_structure_attribute_method_entry, 0);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string name
 * @param int source
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Attribute, __construct) {

	int source;
	zval *name_param = NULL, *source_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &source_param);

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
	source = zephir_get_intval(source_param);


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, source);
	zephir_update_property_this(this_ptr, SL("source"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

