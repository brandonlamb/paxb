
extern zend_class_entry *paxb_filter_objectwalker_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_ObjectWalker);

PHP_METHOD(PAXB_Filter_ObjectWalker, __construct);
PHP_METHOD(PAXB_Filter_ObjectWalker, applyFilterRules);
PHP_METHOD(PAXB_Filter_ObjectWalker, applyFilterRule);
PHP_METHOD(PAXB_Filter_ObjectWalker, getPropertyValue);
PHP_METHOD(PAXB_Filter_ObjectWalker, setPropertyValue);
PHP_METHOD(PAXB_Filter_ObjectWalker, getAccessibleReflectionProperty);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_objectwalker___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_OBJ_INFO(0, filterLoader, PAXB\\Filter\\LoaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_objectwalker_applyfilterrules, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_ARRAY_INFO(0, filterRules, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_objectwalker_applyfilterrule, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_OBJ_INFO(0, filterRule, PAXB\\Filter\\AnnotationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_objectwalker_getpropertyvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_objectwalker_setpropertyvalue, 0, 0, 2)
	ZEND_ARG_INFO(0, propertyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_objectwalker_getaccessiblereflectionproperty, 0, 0, 1)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_objectwalker_method_entry) {
	PHP_ME(PAXB_Filter_ObjectWalker, __construct, arginfo_paxb_filter_objectwalker___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Filter_ObjectWalker, applyFilterRules, arginfo_paxb_filter_objectwalker_applyfilterrules, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_ObjectWalker, applyFilterRule, arginfo_paxb_filter_objectwalker_applyfilterrule, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_ObjectWalker, getPropertyValue, arginfo_paxb_filter_objectwalker_getpropertyvalue, ZEND_ACC_PRIVATE)
	PHP_ME(PAXB_Filter_ObjectWalker, setPropertyValue, arginfo_paxb_filter_objectwalker_setpropertyvalue, ZEND_ACC_PRIVATE)
	PHP_ME(PAXB_Filter_ObjectWalker, getAccessibleReflectionProperty, arginfo_paxb_filter_objectwalker_getaccessiblereflectionproperty, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
