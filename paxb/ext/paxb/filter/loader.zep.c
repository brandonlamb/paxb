
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"


/**
 * Loads the filter that enforces a specific rule.
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Loader) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter, Loader, paxb, filter_loader, paxb_filter_loader_method_entry, 0);

	zend_class_implements(paxb_filter_loader_ce TSRMLS_CC, 1, paxb_filter_loaderinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Loader, getFilterForRule) {

	zend_class_entry *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rule, *filterIdentifier = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rule);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&filterIdentifier, rule, "getfilter",  NULL);
	zephir_check_call_status();
	if (zephir_class_exists(filterIdentifier, 1 TSRMLS_CC)) {
		_0 = zend_fetch_class(Z_STRVAL_P(filterIdentifier), Z_STRLEN_P(filterIdentifier), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _0);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, spl_ce_UnexpectedValueException);
	ZEPHIR_INIT_VAR(_2);
	zephir_get_class(_2, rule, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "Unable to locate filter for: $filterIdentifier defined in ", _2);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "paxb/filter/loader.zep", 25 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

