
extern zend_class_entry *paxb_filter_filters_zend_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_Zend);

PHP_METHOD(PAXB_Filter_Filters_Zend, apply);
PHP_METHOD(PAXB_Filter_Filters_Zend, getZendInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filters_zend_apply, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Binding\\Annotations\\Filter\\AnnotationInterface, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filters_zend_getzendinstance, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_filters_zend_method_entry) {
	PHP_ME(PAXB_Filter_Filters_Zend, apply, arginfo_paxb_filter_filters_zend_apply, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filters_Zend, getZendInstance, arginfo_paxb_filter_filters_zend_getzendinstance, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
