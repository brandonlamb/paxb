
extern zend_class_entry *paxb_binding_annotations_loaderinterface_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_LoaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_loaderinterface_processmetadata, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_annotations_loaderinterface_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Binding_Annotations_LoaderInterface, processMetadata, arginfo_paxb_binding_annotations_loaderinterface_processmetadata)
  PHP_FE_END
};
