
extern zend_class_entry *paxb_xml_binding_structure_attribute_ce;

ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Structure_Attribute);

PHP_METHOD(PAXB_Xml_Binding_Structure_Attribute, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_attribute___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_xml_binding_structure_attribute_method_entry) {
	PHP_ME(PAXB_Xml_Binding_Structure_Attribute, __construct, arginfo_paxb_xml_binding_structure_attribute___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
