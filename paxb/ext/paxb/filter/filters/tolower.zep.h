
extern zend_class_entry *paxb_filter_filters_tolower_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_ToLower);

PHP_METHOD(PAXB_Filter_Filters_ToLower, apply);
PHP_METHOD(PAXB_Filter_Filters_ToLower, useEncoding);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filters_tolower_apply, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Binding\\Annotations\\Filter\\AnnotationInterface, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filters_tolower_useencoding, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Binding\\Annotations\\Filter\\AnnotationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_filters_tolower_method_entry) {
	PHP_ME(PAXB_Filter_Filters_ToLower, apply, arginfo_paxb_filter_filters_tolower_apply, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filters_ToLower, useEncoding, arginfo_paxb_filter_filters_tolower_useencoding, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
