
extern zend_class_entry *paxb_binding_metadata_factoryinterface_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_factoryinterface_getmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_metadata_factoryinterface_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_FactoryInterface, getMetadata, arginfo_paxb_binding_metadata_factoryinterface_getmetadata)
  PHP_FE_END
};
