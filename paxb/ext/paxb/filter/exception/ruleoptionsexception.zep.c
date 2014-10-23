
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Base Exception for errors with rule options
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Exception_RuleOptionsException) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Filter\\Exception, RuleOptionsException, paxb, filter_exception_ruleoptionsexception, paxb_filter_exception_filterexception_ce, paxb_filter_exception_ruleoptionsexception_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(paxb_filter_exception_ruleoptionsexception_ce, SL("options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string $message
 * @param array $options
 */
PHP_METHOD(PAXB_Filter_Exception_RuleOptionsException, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *message_param = NULL, *options_param = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &message_param, &options_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	zephir_get_arrval(options, options_param);


	ZEPHIR_CALL_PARENT(NULL, paxb_filter_exception_ruleoptionsexception_ce, this_ptr, "__construct", NULL, message);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieve options that triggered exception
 *
 * @return array
 */
PHP_METHOD(PAXB_Filter_Exception_RuleOptionsException, getOptions) {


	RETURN_MEMBER(this_ptr, "options");

}

