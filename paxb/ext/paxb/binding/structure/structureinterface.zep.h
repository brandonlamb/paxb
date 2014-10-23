
extern zend_class_entry *paxb_binding_structure_structureinterface_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Structure_StructureInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_structure_structureinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_structure_structureinterface_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_structure_structureinterface_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Binding_Structure_StructureInterface, getName, NULL)
	PHP_ABSTRACT_ME(PAXB_Binding_Structure_StructureInterface, getSource, NULL)
	PHP_ABSTRACT_ME(PAXB_Binding_Structure_StructureInterface, setName, arginfo_paxb_binding_structure_structureinterface_setname)
	PHP_ABSTRACT_ME(PAXB_Binding_Structure_StructureInterface, setSource, arginfo_paxb_binding_structure_structureinterface_setsource)
  PHP_FE_END
};
