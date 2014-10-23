
extern zend_class_entry *paxb_filter_filters_objectawarefilter_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Filters_ObjectAwareFilter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filters_objectawarefilter_setcurrentobject, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_filters_objectawarefilter_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Filter_Filters_ObjectAwareFilter, setCurrentObject, arginfo_paxb_filter_filters_objectawarefilter_setcurrentobject)
	PHP_ABSTRACT_ME(PAXB_Filter_Filters_ObjectAwareFilter, getCurrentObject, NULL)
  PHP_FE_END
};
