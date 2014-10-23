
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


/**
 * Invalid callback passed to rule
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Exception_InvalidCallbackException) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Filter\\Exception, InvalidCallbackException, paxb, filter_exception_invalidcallbackexception, paxb_filter_exception_filterexception_ce, NULL, 0);

	return SUCCESS;

}

