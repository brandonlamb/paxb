
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
 * Base Exception for Filter Package
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Exception_FilterException) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Filter\\Exception, FilterException, paxb, filter_exception_filterexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

