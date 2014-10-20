
extern zend_class_entry *paxb_xml_binding_metadata_metadatafactory_ce;

ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Metadata_MetadataFactory);

PHP_METHOD(PAXB_Xml_Binding_Metadata_MetadataFactory, __construct);
PHP_METHOD(PAXB_Xml_Binding_Metadata_MetadataFactory, getMetadata);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_metadata_metadatafactory___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, loader)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_metadata_metadatafactory_getmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_xml_binding_metadata_metadatafactory_method_entry) {
	PHP_ME(PAXB_Xml_Binding_Metadata_MetadataFactory, __construct, arginfo_paxb_xml_binding_metadata_metadatafactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Xml_Binding_Metadata_MetadataFactory, getMetadata, arginfo_paxb_xml_binding_metadata_metadatafactory_getmetadata, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
