
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
 * @Target({"PROPERTY", "METHOD"})
 */
ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Annotations_XmlElement) {

	ZEPHIR_REGISTER_CLASS_EX(PAXB\\Xml\\Binding\\Annotations, XmlElement, paxb, xml_binding_annotations_xmlelement, paxb_xml_binding_annotations_xmlannotation_ce, NULL, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(paxb_xml_binding_annotations_xmlelement_ce, SL("name"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(paxb_xml_binding_annotations_xmlelement_ce, SL("type"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

