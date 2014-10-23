
extern zend_class_entry *paxb_binding_metadata_container_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_Container);

PHP_METHOD(PAXB_Binding_Metadata_Container, __construct);
PHP_METHOD(PAXB_Binding_Metadata_Container, set);
PHP_METHOD(PAXB_Binding_Metadata_Container, get);
PHP_METHOD(PAXB_Binding_Metadata_Container, has);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_container___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, storage, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_container_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_container_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_container_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_metadata_container_method_entry) {
	PHP_ME(PAXB_Binding_Metadata_Container, __construct, arginfo_paxb_binding_metadata_container___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Binding_Metadata_Container, set, arginfo_paxb_binding_metadata_container_set, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Container, get, arginfo_paxb_binding_metadata_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Container, has, arginfo_paxb_binding_metadata_container_has, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
