
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Filters the values of a given object
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Filter, FilterInterface, paxb, filter_filterinterface, paxb_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Iterates over the properties of the object applying filters and
 * replacing values
 *
 * @param mixed $object
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_FilterInterface, filterEntity);

/**
 * Filters a specific property in an object, replacing the current value
 *
 * @param mixed $object
 * @param string $property
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_FilterInterface, filterProperty);

/**
 * Runs a given value through one or more filter rules returning the
 * filtered value
 *
 * @param mixed $value
 * @param array|Rules\Rule $filter
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_FilterInterface, filterValue);

/**
 * Retrieves the metadata factory for class metdatas
 *
 * @return \PAXB\Binding\Metadata\FactoryInterface
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_FilterInterface, getMetadataFactory);

