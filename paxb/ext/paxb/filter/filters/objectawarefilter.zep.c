
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface ObjectAwareFilter
 *
 * Allows filters to be aware of the object they are being applied to.
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_ObjectAwareFilter) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Filter\\Filters, ObjectAwareFilter, paxb, filter_filters_objectawarefilter, paxb_filter_filters_objectawarefilter_method_entry);

	return SUCCESS;

}

/**
 * Set the current object so that the filter can access it
 *
 * @param mixed $object
 * @return mixed
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_Filters_ObjectAwareFilter, setCurrentObject);

/**
 * Retrieves the current Object to be used
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_Filters_ObjectAwareFilter, getCurrentObject);

