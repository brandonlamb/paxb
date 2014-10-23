
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Base Filter Class
 *
 * Abstract class that defined the basic needs of a "Filter"
 * Filter classes are the enforcers of rules. This means they
 * are the classes that know how a given rule is applied to
 * a value.
 *
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Filter\\Filters, FilterInterface, paxb, filter_filters_filterinterface, paxb_filter_filters_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Enforces the desired filtering on the the value  returning a filtered value.
 *
 * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $rule
 * @param mixed $value
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_Filters_FilterInterface, apply);

