
extern zend_class_entry *paxb_binding_annotations_annotation_ce;

ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_Annotation);

PHP_METHOD(PAXB_Binding_Annotations_Annotation, __construct);
PHP_METHOD(PAXB_Binding_Annotations_Annotation, __get);
PHP_METHOD(PAXB_Binding_Annotations_Annotation, __set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_annotation___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_annotation___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_paxb_binding_annotations_annotation___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(paxb_binding_annotations_annotation_method_entry) {
	PHP_ME(PAXB_Binding_Annotations_Annotation, __construct, arginfo_paxb_binding_annotations_annotation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(PAXB_Binding_Annotations_Annotation, __get, arginfo_paxb_binding_annotations_annotation___get, ZEND_ACC_PUBLIC)
	PHP_ME(PAXB_Binding_Annotations_Annotation, __set, arginfo_paxb_binding_annotations_annotation___set, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
