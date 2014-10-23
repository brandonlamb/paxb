
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Zend Filter
 *
 * Instantiates and runs Zend Filters (from ZF2)
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_Zend) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter\\Filters, Zend, paxb, filter_filters_zend, paxb_filter_filters_zend_method_entry, 0);

	zend_class_implements(paxb_filter_filters_zend_ce TSRMLS_CC, 1, paxb_filter_filters_filterinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_Zend, apply) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rule, *value, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &value);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, rule, SL("className"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, rule, SL("zendOptions"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getzendinstance", NULL, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "filter", NULL, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Instantiates a configured Zend Filter, if it exists
 *
 * @param string className
 * @param array $options
 * @return \Zend\Filter\FilterInterface
 * @throws \DMS\Filter\Exception\InvalidZendFilterException
 */
PHP_METHOD(PAXB_Filter_Filters_Zend, getZendInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_3, *_5, *_6;
	zval *options = NULL;
	zval *className_param = NULL, *options_param = NULL, *reflectionClass, *filter, *e = NULL, _0, *_1, *_4;
	zval *className = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &options_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}
	zephir_get_arrval(options, options_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Zend\\Filter", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, className, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Zend\\Filter\\", className);
		ZEPHIR_CPY_WRT(className, _2);
	}
	if (!(zephir_class_exists(className, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(paxb_filter_exception_invalidzendfilterexception_ce, "Could not find or autoload: className", "paxb/filter/filters/zend.zep", 40);
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(reflectionClass);
		_3 = zend_fetch_class(SL("ReflectionMethod"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(reflectionClass, _3);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "setOptions", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, reflectionClass, "__construct", NULL, className, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(filter);
		_5 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(filter, _5);
		if (zephir_has_constructor(filter TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, filter, "__construct", NULL);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_METHOD(NULL, filter, "setoptions", NULL, options);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_CCTOR(filter);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_is_instance_of(e, SL("ReflectionException") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			_6 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _6);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, options);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	}
	ZEPHIR_MM_RESTORE();

}

