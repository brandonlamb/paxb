
extern zend_class_entry *paxb_filter_loaderinterface_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_LoaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_loaderinterface_getfilterforrule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, rule, PAXB\\Binding\\Annotations\\Filter\\AnnotationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_loaderinterface_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Filter_LoaderInterface, getFilterForRule, arginfo_paxb_filter_loaderinterface_getfilterforrule)
  PHP_FE_END
};
