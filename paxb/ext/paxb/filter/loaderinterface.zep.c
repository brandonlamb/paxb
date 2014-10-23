
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface LoaderInterface
 *
 * Defines the required interface for a loader capable of finding the executor of a specific rule.
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_LoaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Filter, LoaderInterface, paxb, filter_loaderinterface, paxb_filter_loaderinterface_method_entry);

	return SUCCESS;

}

/**
 * Finds the filter responsible for executing a specific rule
 *
 * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $rule
 * @return \PAXB\Filter\Filters\FilterInterface
 *
 * @throws \UnexpectedValueException If filter can't be located
 */
ZEPHIR_DOC_METHOD(PAXB_Filter_LoaderInterface, getFilterForRule);

