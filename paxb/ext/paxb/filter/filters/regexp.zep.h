
extern zend_class_entry *paxb_filter_filters_regexp_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_RegExp);

PHP_METHOD(PAXB_Filter_Filters_RegExp, apply);
PHP_METHOD(PAXB_Filter_Filters_RegExp, checkUnicodeSupport);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filters_regexp_apply, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Binding\\Annotations\\Filter\\AnnotationInterface, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_filters_regexp_method_entry) {
	PHP_ME(PAXB_Filter_Filters_RegExp, apply, arginfo_paxb_filter_filters_regexp_apply, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Filter_Filters_RegExp, checkUnicodeSupport, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
