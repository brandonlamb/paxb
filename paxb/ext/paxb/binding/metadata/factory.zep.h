
extern zend_class_entry *paxb_binding_metadata_factory_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_Factory);

PHP_METHOD(PAXB_Binding_Metadata_Factory, __construct);
PHP_METHOD(PAXB_Binding_Metadata_Factory, getMetadata);
PHP_METHOD(PAXB_Binding_Metadata_Factory, parseMetadata);
PHP_METHOD(PAXB_Binding_Metadata_Factory, loadParentMetadata);
PHP_METHOD(PAXB_Binding_Metadata_Factory, loadInterfaceMetadata);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_factory___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, loader)
	ZEND_ARG_OBJ_INFO(0, container, PAXB\\Binding\\Metadata\\Container, 0)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_factory_getmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_factory_parsemetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_factory_loadparentmetadata, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_factory_loadinterfacemetadata, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_metadata_factory_method_entry) {
	PHP_ME(PAXB_Binding_Metadata_Factory, __construct, arginfo_paxb_binding_metadata_factory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Binding_Metadata_Factory, getMetadata, arginfo_paxb_binding_metadata_factory_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Factory, parseMetadata, arginfo_paxb_binding_metadata_factory_parsemetadata, ZEND_ACC_PROTECTED)
	PHP_ME(PAXB_Binding_Metadata_Factory, loadParentMetadata, arginfo_paxb_binding_metadata_factory_loadparentmetadata, ZEND_ACC_PROTECTED)
	PHP_ME(PAXB_Binding_Metadata_Factory, loadInterfaceMetadata, arginfo_paxb_binding_metadata_factory_loadinterfacemetadata, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
