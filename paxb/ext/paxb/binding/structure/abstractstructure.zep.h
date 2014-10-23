
extern zend_class_entry *paxb_binding_structure_abstractstructure_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Structure_AbstractStructure);

PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, getName);
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, getSource);
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, setName);
PHP_METHOD(PAXB_Binding_Structure_AbstractStructure, setSource);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_structure_abstractstructure_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_structure_abstractstructure_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_structure_abstractstructure_method_entry) {
	PHP_ME(PAXB_Binding_Structure_AbstractStructure, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Structure_AbstractStructure, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Structure_AbstractStructure, setName, arginfo_paxb_binding_structure_abstractstructure_setname, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Structure_AbstractStructure, setSource, arginfo_paxb_binding_structure_abstractstructure_setsource, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
