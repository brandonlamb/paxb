
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Integer Filter
 * Converts content into an Int
 * @subpackage Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_Integer) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter\\Filters, Integer, paxb, filter_filters_integer, paxb_filter_filters_integer_method_entry, 0);

	zend_class_implements(paxb_filter_filters_integer_ce TSRMLS_CC, 1, paxb_filter_filters_filterinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filters_Integer, apply) {

	zval *rule, *value;

	zephir_fetch_params(0, 2, 0, &rule, &value);



	if (!(zephir_instance_of_ev(rule, paxb_binding_annotations_filter_annotationinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Binding\\\\Annotations\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	RETURN_LONG(zephir_get_intval(value));

}

