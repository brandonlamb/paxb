
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Structure_Element) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Xml\\Binding\\Structure, Element, paxb, xml_binding_structure_element, paxb_binding_structure_abstractstructure_ce, paxb_xml_binding_structure_element_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(paxb_xml_binding_structure_element_ce, SL("type"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(paxb_xml_binding_structure_element_ce, SL("typeValue"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(paxb_xml_binding_structure_element_ce, SL("wrapperName"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(paxb_xml_binding_structure_element_ce, SL("phpCollection"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * @var int
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * @var string
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getTypeValue) {


	RETURN_MEMBER(this_ptr, "typeValue");

}

/**
 * @var string
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getWrapperName) {


	RETURN_MEMBER(this_ptr, "wrapperName");

}

/**
 * @var bool
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getPhpCollection) {


	RETURN_MEMBER(this_ptr, "phpCollection");

}

/**
 * Constructor
 *
 * @param string name
 * @param int source
 * @param int type
 * @param string typeValue
 * @param string wrapperName
 * @param bool phpCollection
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, __construct) {

	zend_bool phpCollection;
	int source, type;
	zval *name_param = NULL, *source_param = NULL, *type_param = NULL, *typeValue_param = NULL, *wrapperName_param = NULL, *phpCollection_param = NULL, *_0, *_1, _2, *_3;
	zval *name = NULL, *typeValue = NULL, *wrapperName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 4, &name_param, &source_param, &type_param, &typeValue_param, &wrapperName_param, &phpCollection_param);

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
	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!typeValue_param) {
		ZEPHIR_INIT_VAR(typeValue);
		ZVAL_STRING(typeValue, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(typeValue_param) != IS_STRING && Z_TYPE_P(typeValue_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'typeValue' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(typeValue_param) == IS_STRING)) {
		zephir_get_strval(typeValue, typeValue_param);
	} else {
		ZEPHIR_INIT_VAR(typeValue);
		ZVAL_EMPTY_STRING(typeValue);
	}
	}
	if (!wrapperName_param) {
		ZEPHIR_INIT_VAR(wrapperName);
		ZVAL_EMPTY_STRING(wrapperName);
	} else {
	if (unlikely(Z_TYPE_P(wrapperName_param) != IS_STRING && Z_TYPE_P(wrapperName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'wrapperName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(wrapperName_param) == IS_STRING)) {
		zephir_get_strval(wrapperName, wrapperName_param);
	} else {
		ZEPHIR_INIT_VAR(wrapperName);
		ZVAL_EMPTY_STRING(wrapperName);
	}
	}
	if (!phpCollection_param) {
		phpCollection = 0;
	} else {
		phpCollection = zephir_get_boolval(phpCollection_param);
	}


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, type);
	zephir_gettype(_1, &_2 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_1, "null")) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_LONG(_0, 1);
	} else {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_LONG(_0, type);
	}
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("typeValue"), typeValue TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, source);
	zephir_update_property_this(this_ptr, SL("source"), _3 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("wrapperName"), wrapperName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("phpCollection"), phpCollection ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $wrapperName
 * @return Element
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, setWrapperName) {

	zval *wrapperName_param = NULL;
	zval *wrapperName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &wrapperName_param);

	if (unlikely(Z_TYPE_P(wrapperName_param) != IS_STRING && Z_TYPE_P(wrapperName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'wrapperName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(wrapperName_param) == IS_STRING)) {
		zephir_get_strval(wrapperName, wrapperName_param);
	} else {
		ZEPHIR_INIT_VAR(wrapperName);
		ZVAL_EMPTY_STRING(wrapperName);
	}


	zephir_update_property_this(this_ptr, SL("wrapperName"), wrapperName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param string $typeValue
 * @return Element
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, setTypeValue) {

	zval *typeValue_param = NULL, *_0;
	zval *typeValue = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &typeValue_param);

	if (unlikely(Z_TYPE_P(typeValue_param) != IS_STRING && Z_TYPE_P(typeValue_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'typeValue' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(typeValue_param) == IS_STRING)) {
		zephir_get_strval(typeValue, typeValue_param);
	} else {
		ZEPHIR_INIT_VAR(typeValue);
		ZVAL_EMPTY_STRING(typeValue);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("type"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("typeValue"), typeValue TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param boolean $phpCollection
 * @return Element
 */
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, setPhpCollection) {

	zval *phpCollection_param = NULL;
	zend_bool phpCollection;

	zephir_fetch_params(0, 1, 0, &phpCollection_param);

	phpCollection = zephir_get_boolval(phpCollection_param);


	zephir_update_property_this(this_ptr, SL("phpCollection"), phpCollection ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

