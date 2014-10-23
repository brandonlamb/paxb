
extern zend_class_entry *paxb_filter_filter_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Filter);

PHP_METHOD(PAXB_Filter_Filter, __construct);
PHP_METHOD(PAXB_Filter_Filter, filterEntity);
PHP_METHOD(PAXB_Filter_Filter, filterProperty);
PHP_METHOD(PAXB_Filter_Filter, filterValue);
PHP_METHOD(PAXB_Filter_Filter, getMetadataFactory);
PHP_METHOD(PAXB_Filter_Filter, walkObject);
PHP_METHOD(PAXB_Filter_Filter, walkRuleChain);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filter___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, metadataFactory, PAXB\\Binding\\Metadata\\FactoryInterface, 0)
	ZEND_ARG_OBJ_INFO(0, filterLoader, PAXB\\Filter\\LoaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filter_filterentity, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filter_filterproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filter_filtervalue, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, rule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filter_walkobject, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_INFO(0, limitProperty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filter_walkrulechain, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, rules, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_filter_method_entry) {
	PHP_ME(PAXB_Filter_Filter, __construct, arginfo_paxb_filter_filter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Filter_Filter, filterEntity, arginfo_paxb_filter_filter_filterentity, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filter, filterProperty, arginfo_paxb_filter_filter_filterproperty, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filter, filterValue, arginfo_paxb_filter_filter_filtervalue, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filter, getMetadataFactory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filter, walkObject, arginfo_paxb_filter_filter_walkobject, ZEND_ACC_PROTECTED)
	PHP_ME(PAXB_Filter_Filter, walkRuleChain, arginfo_paxb_filter_filter_walkrulechain, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
