
extern zend_class_entry *paxb_filter_exception_ruleoptionsexception_ce;

ZEPHIR_INIT_CLASS(PAXB_Filter_Exception_RuleOptionsException);

PHP_METHOD(PAXB_Filter_Exception_RuleOptionsException, __construct);
PHP_METHOD(PAXB_Filter_Exception_RuleOptionsException, getOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_filter_exception_ruleoptionsexception___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_filter_exception_ruleoptionsexception_method_entry) {
	PHP_ME(PAXB_Filter_Exception_RuleOptionsException, __construct, arginfo_paxb_filter_exception_ruleoptionsexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Filter_Exception_RuleOptionsException, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
