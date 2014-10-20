
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Annotation interface
 *
 * @package \PAXB\Filter\Annotations
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Annotations_AnnotationInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Filter\\Annotations, AnnotationInterface, paxb, filter_annotations_annotationinterface, NULL);

	return SUCCESS;

}

