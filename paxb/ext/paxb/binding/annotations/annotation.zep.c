
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Annotations class.
 */
ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_Annotation) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Binding\\Annotations, Annotation, paxb, binding_annotations_annotation, paxb_binding_annotations_annotation_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(paxb_binding_annotations_annotation_ce, SL("value"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param array data Key-value for properties to be defined in this class.
 */
PHP_METHOD(PAXB_Binding_Annotations_Annotation, __construct) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *key = NULL, *value = NULL, **_2, *_3 = NULL, *_4 = NULL, _5 = zval_used_for_init, *_6 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "paxb/binding/annotations/annotation.zep", 34);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (!(zephir_isset_property_zval(this_ptr, key TSRMLS_CC))) {
			ZEPHIR_INIT_LNVAR(_3);
			object_init_ex(_3, spl_ce_RuntimeException);
			ZEPHIR_INIT_NVAR(_4);
			zephir_get_class(_4, this_ptr, 0 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "Unknown property '%s' on annotation '%s'.", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_5, key, _4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_8, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "paxb/binding/annotations/annotation.zep", 29 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Error handler for unknown property accessor in Annotation class.
 *
 * @param string name Unknown property name.
 * @throws \BadMethodCallException
 */
PHP_METHOD(PAXB_Binding_Annotations_Annotation, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *name_param = NULL, *_0, *_1, _2, *_3 = NULL;
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


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Unknown property '%s' on annotation '%s'.", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, name, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "paxb/binding/annotations/annotation.zep", 46 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Error handler for unknown property mutator in Annotation class.
 *
 * @param string name  Unknown property name.
 * @param mixed value Property value.
 * @throws \BadMethodCallException
 */
PHP_METHOD(PAXB_Binding_Annotations_Annotation, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *name_param = NULL, *value, *_0, *_1, _2, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

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


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Unknown property '%s' on annotation '%s'.", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, name, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "paxb/binding/annotations/annotation.zep", 60 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

