
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


/**
 * RegExp Filter
 *
 * Filter using preg_replace and unicode or non-unicode patterns
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_RegExp) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter\\Filters, RegExp, paxb, filter_filters_regexp, paxb_filter_filters_regexp_method_entry, 0);

	/**
	 * Defines if Unicode is supported
	 *
	 * @var boolean
	 */
	zend_declare_property_null(paxb_filter_filters_regexp_ce, SL("unicodeEnabled"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(paxb_filter_filters_regexp_ce TSRMLS_CC, 1, paxb_filter_filters_filterinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_RegExp, apply) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rule, *value, *pattern = NULL, *_0 = NULL, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &value);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkunicodesupport",  NULL);
	zephir_check_call_status();
	_1 = zephir_is_true(_0);
	if (_1) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, rule, SL("unicodePattern"), PH_NOISY_CC);
		_1 = Z_TYPE_P(_2) != IS_NULL;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(pattern);
		zephir_read_property(&pattern, rule, SL("unicodePattern"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, rule, SL("pattern"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(pattern, _3);
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_5, pattern, _4, value);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Verifies that Regular Expression functions support unicode
 * @return boolean
 */
PHP_METHOD(PAXB_Filter_Filters_RegExp, checkUnicodeSupport) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *_0, *_1, *_2, *_3 = NULL, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, paxb_filter_filters_regexp_ce, SL("unicodeEnabled") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "/\\pL/u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "a", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_4, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			zephir_update_static_property_ce(paxb_filter_filters_regexp_ce, SL("unicodeEnabled"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_static_property_ce(paxb_filter_filters_regexp_ce, SL("unicodeEnabled"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	_5 = zephir_fetch_static_property_ce(paxb_filter_filters_regexp_ce, SL("unicodeEnabled") TSRMLS_CC);
	RETURN_CTOR(_5);

}

