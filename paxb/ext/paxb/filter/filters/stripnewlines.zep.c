
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * StripNewlines Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_StripNewlines) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter\\Filters, StripNewlines, paxb, filter_filters_stripnewlines, paxb_filter_filters_stripnewlines_method_entry, 0);

	zend_class_implements(paxb_filter_filters_stripnewlines_ce TSRMLS_CC, 1, paxb_filter_filters_filterinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_StripNewlines, apply) {

	zval *_0;
	zval *rule, *value, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &value);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "\n", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "\r", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	zephir_fast_str_replace(return_value, _0, &_2, value);
	RETURN_MM();

}

