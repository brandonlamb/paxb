
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Annotation interface
 *
 * @package \PAXB\Binding\Annotations\Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_Filter_AnnotationInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Binding\\Annotations\\Filter, AnnotationInterface, paxb, binding_annotations_filter_annotationinterface, NULL);

	return SUCCESS;

}

