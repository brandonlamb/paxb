
extern zend_class_entry *paxb_binding_annotations_abstractloader_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_AbstractLoader);

PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, __construct);
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processMetadata);
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processClassAnnotations);
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processMethodAnnotations);
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processPropertyAnnotations);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_abstractloader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, reader)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_abstractloader_processmetadata, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_abstractloader_processclassannotations, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_abstractloader_processmethodannotations, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_abstractloader_processpropertyannotations, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_annotations_abstractloader_method_entry) {
	PHP_ME(PAXB_Binding_Annotations_AbstractLoader, __construct, arginfo_paxb_binding_annotations_abstractloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Binding_Annotations_AbstractLoader, processMetadata, arginfo_paxb_binding_annotations_abstractloader_processmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Annotations_AbstractLoader, processClassAnnotations, arginfo_paxb_binding_annotations_abstractloader_processclassannotations, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(PAXB_Binding_Annotations_AbstractLoader, processMethodAnnotations, arginfo_paxb_binding_annotations_abstractloader_processmethodannotations, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(PAXB_Binding_Annotations_AbstractLoader, processPropertyAnnotations, arginfo_paxb_binding_annotations_abstractloader_processpropertyannotations, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
  PHP_FE_END
};
