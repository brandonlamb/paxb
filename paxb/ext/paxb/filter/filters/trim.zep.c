
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
#include "kernel/string.h"


/**
 * Trim Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_Trim) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter\\Filters, Trim, paxb, filter_filters_trim, paxb_filter_filters_trim_method_entry, 0);

	zend_class_implements(paxb_filter_filters_trim_ce TSRMLS_CC, 1, paxb_filter_filters_filterinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_Trim, apply) {

	zval *rule, *value, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &value);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, rule, SL("charlist"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		zephir_fast_trim(return_value, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, rule, SL("charlist"), PH_NOISY_CC);
	zephir_fast_trim(return_value, value, _1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	RETURN_MM();

}

