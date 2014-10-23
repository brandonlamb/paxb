
extern zend_class_entry *paxb_binding_metadata_metadatainterface_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_MetadataInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadatainterface_addpropertyrule, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Filter\\Annotations\\AnnotationsInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadatainterface_getpropertyrules, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadatainterface_mergerules, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_metadata_metadatainterface_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_MetadataInterface, getFilteredProperties, NULL)
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_MetadataInterface, addPropertyRule, arginfo_paxb_binding_metadata_metadatainterface_addpropertyrule)
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_MetadataInterface, getPropertyRules, arginfo_paxb_binding_metadata_metadatainterface_getpropertyrules)
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_MetadataInterface, mergeRules, arginfo_paxb_binding_metadata_metadatainterface_mergerules)
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_MetadataInterface, getClassName, NULL)
	PHP_ABSTRACT_ME(PAXB_Binding_Metadata_MetadataInterface, getReflectionClass, NULL)
  PHP_FE_END
};
