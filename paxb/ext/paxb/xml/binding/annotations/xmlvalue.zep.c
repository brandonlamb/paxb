
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * @Annotation
 */
ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Annotations_XmlValue) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Xml\\Binding\\Annotations, XmlValue, paxb, xml_binding_annotations_xmlvalue, paxb_xml_binding_annotations_xmlannotation_ce, NULL, 0);

	return SUCCESS;

}

