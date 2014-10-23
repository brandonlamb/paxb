
extern zend_class_entry *paxb_filter_filterinterface_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filterinterface_filterentity, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filterinterface_filterproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_filterinterface_filtervalue, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(PAXB_Filter_FilterInterface, filterEntity, arginfo_paxb_filter_filterinterface_filterentity)
	PHP_ABSTRACT_ME(PAXB_Filter_FilterInterface, filterProperty, arginfo_paxb_filter_filterinterface_filterproperty)
	PHP_ABSTRACT_ME(PAXB_Filter_FilterInterface, filterValue, arginfo_paxb_filter_filterinterface_filtervalue)
	PHP_ABSTRACT_ME(PAXB_Filter_FilterInterface, getMetadataFactory, NULL)
  PHP_FE_END
};
