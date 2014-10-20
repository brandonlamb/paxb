
extern zend_class_entry *paxb_xml_binding_structure_element_ce;

ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Structure_Element);

PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getType);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getTypeValue);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getWrapperName);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, getPhpCollection);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, __construct);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, setWrapperName);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, setTypeValue);
PHP_METHOD(PAXB_Xml_Binding_Structure_Element, setPhpCollection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_element___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, typeValue)
	ZEND_ARG_INFO(0, wrapperName)
	ZEND_ARG_INFO(0, phpCollection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_element_setwrappername, 0, 0, 1)
	ZEND_ARG_INFO(0, wrapperName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_element_settypevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, typeValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_element_setphpcollection, 0, 0, 1)
	ZEND_ARG_INFO(0, phpCollection)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_xml_binding_structure_element_method_entry) {
	PHP_ME(PAXB_Xml_Binding_Structure_Element, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, getTypeValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, getWrapperName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, getPhpCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, __construct, arginfo_paxb_xml_binding_structure_element___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, setWrapperName, arginfo_paxb_xml_binding_structure_element_setwrappername, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, setTypeValue, arginfo_paxb_xml_binding_structure_element_settypevalue, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Element, setPhpCollection, arginfo_paxb_xml_binding_structure_element_setphpcollection, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
