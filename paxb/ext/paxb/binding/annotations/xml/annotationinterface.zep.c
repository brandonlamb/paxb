
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
 * @package \PAXB\Binding\Annotations\Xml
 */
ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_Xml_AnnotationInterface) {

	ZEPHIR_REGISTER_INTERFACE(PAXB\\Binding\\Annotations\\Xml, AnnotationInterface, paxb, binding_annotations_xml_annotationinterface, NULL);

	return SUCCESS;

}

