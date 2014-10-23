
extern zend_class_entry *paxb_filter_loader_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Loader);

PHP_METHOD(PAXB_Filter_Loader, getFilterForRule);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_loader_getfilterforrule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Binding\\Annotations\\Filter\\AnnotationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_loader_method_entry) {
	PHP_ME(PAXB_Filter_Loader, getFilterForRule, arginfo_paxb_filter_loader_getfilterforrule, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
