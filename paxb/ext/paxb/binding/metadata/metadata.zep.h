
extern zend_class_entry *paxb_binding_metadata_metadata_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_Metadata);

PHP_METHOD(PAXB_Binding_Metadata_Metadata, __construct);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getClassName);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getName);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getAttributes);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getElements);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getValueElement);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getFilteredProperties);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getReflectionClass);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, getPropertyRules);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, addPropertyRule);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, mergeRules);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, addAttributes);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, addElement);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, setName);
PHP_METHOD(PAXB_Binding_Metadata_Metadata, setValueElement);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_getpropertyrules, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_addpropertyrule, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Filter\\Annotations\\AnnotationsInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_mergerules, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, metadata, PAXB\\Binding\\Metadata\\MetadataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_addattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, fieldName)
	ZEND_ARG_OBJ_INFO(0, attribute, PAXB\\Xml\\Binding\\Structure\\Attribute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_addelement, 0, 0, 2)
	ZEND_ARG_INFO(0, fieldName)
	ZEND_ARG_OBJ_INFO(0, element, PAXB\\Xml\\Binding\\Structure\\Element, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_metadata_metadata_setvalueelement, 0, 0, 1)
	ZEND_ARG_INFO(0, valueElement)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_metadata_metadata_method_entry) {
	PHP_ME(PAXB_Binding_Metadata_Metadata, __construct, arginfo_paxb_binding_metadata_metadata___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getClassName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getElements, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getValueElement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getFilteredProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getReflectionClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, getPropertyRules, arginfo_paxb_binding_metadata_metadata_getpropertyrules, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, addPropertyRule, arginfo_paxb_binding_metadata_metadata_addpropertyrule, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, mergeRules, arginfo_paxb_binding_metadata_metadata_mergerules, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, addAttributes, arginfo_paxb_binding_metadata_metadata_addattributes, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, addElement, arginfo_paxb_binding_metadata_metadata_addelement, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, setName, arginfo_paxb_binding_metadata_metadata_setname, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Metadata_Metadata, setValueElement, arginfo_paxb_binding_metadata_metadata_setvalueelement, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
