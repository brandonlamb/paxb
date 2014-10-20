
extern zend_class_entry *paxb_xml_binding_metadata_factory_ce;

ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Metadata_Factory);

PHP_METHOD(PAXB_Xml_Binding_Metadata_Factory, __construct);
PHP_METHOD(PAXB_Xml_Binding_Metadata_Factory, getMetadata);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_metadata_factory___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, loader)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_xml_binding_metadata_factory_getmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_xml_binding_metadata_factory_method_entry) {
	PHP_ME(PAXB_Xml_Binding_Metadata_Factory, __construct, arginfo_paxb_xml_binding_metadata_factory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Xml_Binding_Metadata_Factory, getMetadata, arginfo_paxb_xml_binding_metadata_factory_getmetadata, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
