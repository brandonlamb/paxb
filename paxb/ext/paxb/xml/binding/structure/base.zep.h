
extern zend_class_entry *paxb_xml_binding_structure_base_ce;

ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Structure_Base);

PHP_METHOD(PAXB_Xml_Binding_Structure_Base, getName);
PHP_METHOD(PAXB_Xml_Binding_Structure_Base, getSource);
PHP_METHOD(PAXB_Xml_Binding_Structure_Base, setName);
PHP_METHOD(PAXB_Xml_Binding_Structure_Base, setSource);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_base_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_structure_base_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_xml_binding_structure_base_method_entry) {
	PHP_ME(PAXB_Xml_Binding_Structure_Base, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Base, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Base, setName, arginfo_paxb_xml_binding_structure_base_setname, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Xml_Binding_Structure_Base, setSource, arginfo_paxb_xml_binding_structure_base_setsource, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
