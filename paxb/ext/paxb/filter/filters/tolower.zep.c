
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * ToLower Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_ToLower) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter\\Filters, ToLower, paxb, filter_filters_tolower, paxb_filter_filters_tolower_method_entry, 0);

	zend_class_implements(paxb_filter_filters_tolower_ce TSRMLS_CC, 1, paxb_filter_filters_filterinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_ToLower, apply) {

	zval *_2 = NULL, *_4 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rule, *value, *_0 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &value);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "useencoding", &_1, rule);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		zephir_get_strval(_2, value);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, rule, SL("encoding"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, _2, _3);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_get_strval(_4, value);
	zephir_fast_strtolower(return_value, _4);
	RETURN_MM();

}

/**
 * Verify is encoding is set and if we have the proper
 * function to use it
 *
 * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $rule
 * @return boolean
 *
 * @throws \DMS\Filter\Exception\FilterException
 */
PHP_METHOD(PAXB_Filter_Filters_ToLower, useEncoding) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rule, *encodings = NULL, *_0, *_1 = NULL, _2, *_4, *_5, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rule);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, rule, SL("encoding"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	if (!((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(paxb_filter_exception_filterexception_ce, "mbstring is required to use ToLower with an encoding.", "paxb/filter/filters/tolower.zep", 42);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "mb_list_encodings", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "strtolower", 0);
	ZEPHIR_CALL_FUNCTION(&encodings, "array_map", &_3, &_2, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, rule, SL("encoding"), PH_NOISY_CC);
	zephir_fast_strtolower(_4, _5);
	if (!(zephir_fast_in_array(_4, encodings TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, paxb_filter_exception_filterexception_ce);
		ZEPHIR_OBS_VAR(_7);
		zephir_read_property(&_7, rule, SL("encoding"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SVS(_8, "mbstring does not support the '", _7, "' encoding");
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "paxb/filter/filters/tolower.zep", 50 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

