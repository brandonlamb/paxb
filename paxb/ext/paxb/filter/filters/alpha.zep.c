
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


/**
 * Alpha Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_Alpha) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Filter\\Filters, Alpha, paxb, filter_filters_alpha, paxb_filter_filters_regexp_ce, paxb_filter_filters_alpha_method_entry, 0);

	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_Alpha, apply) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *rule, *value, *whitespaceChar, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &value);

	ZEPHIR_SEPARATE_PARAM(rule);


	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, rule, SL("allowWhitespace"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(whitespaceChar);
		ZVAL_STRING(whitespaceChar, " ", 1);
	} else {
		ZEPHIR_INIT_BNVAR(whitespaceChar);
		ZVAL_STRING(whitespaceChar, "", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "/[^\\p{L}", whitespaceChar, "]/u");
	zephir_update_property_zval(rule, SL("unicodePattern"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "/[^a-zA-Z", whitespaceChar, "]/");
	zephir_update_property_zval(rule, SL("pattern"), _2 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(paxb_filter_filters_alpha_ce, this_ptr, "apply", &_3, rule, value);
	zephir_check_call_status();
	RETURN_MM();

}

