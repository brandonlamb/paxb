
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Metadata_Metadata) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Xml\\Binding\\Metadata, Metadata, paxb, xml_binding_metadata_metadata, paxb_xml_binding_metadata_metadata_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("className"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Element[]
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("valueElement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Properties that contain filtering rules
	 * @var array
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("filteredProperties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \ReflectionClass
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_metadata_ce, SL("reflection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(paxb_xml_binding_metadata_metadata_ce, SL("RUNTIME_TYPE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(paxb_xml_binding_metadata_metadata_ce, SL("DEFINED_TYPE"), 2 TSRMLS_CC);

	zend_class_implements(paxb_xml_binding_metadata_metadata_ce TSRMLS_CC, 1, paxb_xml_binding_metadata_metadatainterface_ce);
	return SUCCESS;

}

/**
 * @param string $className
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *_0, *_2, *_3, *_4, *_5;
	zval *className = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(className, "")) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SS(_1, "Metadata:__construct", ": must pass non-empty className");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "paxb/xml/binding/metadata/metadata.zep", 58 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("className"), className TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_update_property_this(this_ptr, SL("name"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("attributes"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("elements"), _4 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_update_property_this(this_ptr, SL("valueElement"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("filteredProperties"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get name of class represented in this Metadata object
 *
 * @return string
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getClassName) {


	RETURN_MEMBER(this_ptr, "className");

}

/**
 * @return string
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * @return array
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getAttributes) {


	RETURN_MEMBER(this_ptr, "attributes");

}

/**
 * @return \PAXB\Xml\Binding\Metadata\Element[]
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getElements) {


	RETURN_MEMBER(this_ptr, "elements");

}

/**
 * @return string
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getValueElement) {


	RETURN_MEMBER(this_ptr, "valueElement");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getFilteredProperties) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("filteredProperties"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * Returns a ReflectionClass instance for this class
 *
 * @return \ReflectionClass
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getReflectionClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zval *_0, *_1, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("reflection"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_1, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getclassname",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("reflection"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "reflection");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, getPropertyRules) {

	zval *property_param = NULL, *_0, *_1, *_2, *_3;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("filteredProperties"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, property))) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("filteredProperties"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, property, PH_NOISY | PH_READONLY, "paxb/xml/binding/metadata/metadata.zep", 142 TSRMLS_CC);
	zephir_array_fetch_string(&_3, _2, SL("rules"), PH_NOISY | PH_READONLY, "paxb/xml/binding/metadata/metadata.zep", 142 TSRMLS_CC);
	RETURN_CTOR(_3);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, addPropertyRule) {

	zval *_1;
	zval *property_param = NULL, *rule, *_0, *_2;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &rule);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	if (!(zephir_is_instance_of(rule, SL("PAXB\\Filter\\Annotations\\AnnotationsInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'rule' must be an instance of 'PAXB\\\\Filter\\\\Annotations\\\\AnnotationsInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("filteredProperties"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, property))) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 2);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_update_string(&_1, SL("rules"), &_2, PH_COPY | PH_SEPARATE);
		zephir_update_property_array(this_ptr, SL("filteredProperties"), property, _1 TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("filteredProperties"), &rule TSRMLS_CC, SL("zsa"), 3, property, SL("rules"));
	RETURN_THIS();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, mergeRules) {

	zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_2, *_6;
	HashPosition _1, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata, *property = NULL, *rule = NULL, *_0 = NULL, **_3, *_4 = NULL, **_7, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metadata);



	if (!(zephir_instance_of_ev(metadata, paxb_xml_binding_metadata_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metadata' must be an instance of 'PAXB\\\\Xml\\\\Binding\\\\Metadata\\\\MetadataInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, metadata, "getfilteredproperties",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "paxb/xml/binding/metadata/metadata.zep", 172);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(property, _3);
		ZEPHIR_CALL_METHOD(&_4, metadata, "getpropertyrules", NULL, property);
		zephir_check_call_status();
		zephir_is_iterable(_4, &_6, &_5, 0, 0, "paxb/xml/binding/metadata/metadata.zep", 170);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(rule, _7);
			ZEPHIR_INIT_LNVAR(_8);
			if (zephir_clone(_8, rule TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addpropertyrule", &_9, property, _8);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

/**
 * @param string $fieldName
 * @param \PAXB\Xml\Binding\Structure\Attribute $attribute
 * @return \PAXB\Xml\Binding\MetadataInterface
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, addAttributes) {

	zval *fieldName_param = NULL, *attribute;
	zval *fieldName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &fieldName_param, &attribute);

	if (unlikely(Z_TYPE_P(fieldName_param) != IS_STRING && Z_TYPE_P(fieldName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fieldName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(fieldName_param) == IS_STRING)) {
		zephir_get_strval(fieldName, fieldName_param);
	} else {
		ZEPHIR_INIT_VAR(fieldName);
		ZVAL_EMPTY_STRING(fieldName);
	}


	if (!(zephir_instance_of_ev(attribute, paxb_xml_binding_structure_attribute_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'attribute' must be an instance of 'PAXB\\\\Xml\\\\Binding\\\\Structure\\\\Attribute'", "", 0);
		return;
	}
	zephir_update_property_array(this_ptr, SL("attributes"), fieldName, attribute TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param string $fieldName
 * @param \PAXB\Xml\Binding\Structure\Element $element
 * @return \PAXB\Xml\Binding\MetadataInterface
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, addElement) {

	zval *fieldName_param = NULL, *element;
	zval *fieldName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &fieldName_param, &element);

	if (unlikely(Z_TYPE_P(fieldName_param) != IS_STRING && Z_TYPE_P(fieldName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fieldName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(fieldName_param) == IS_STRING)) {
		zephir_get_strval(fieldName, fieldName_param);
	} else {
		ZEPHIR_INIT_VAR(fieldName);
		ZVAL_EMPTY_STRING(fieldName);
	}


	if (!(zephir_instance_of_ev(element, paxb_xml_binding_structure_element_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'element' must be an instance of 'PAXB\\\\Xml\\\\Binding\\\\Structure\\\\Element'", "", 0);
		return;
	}
	zephir_update_property_array(this_ptr, SL("elements"), fieldName, element TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param string $name
 * @return \PAXB\Xml\Binding\MetadataInterface
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, setName) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, name, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("name"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param string $valueElement
 * @return \PAXB\Xml\Binding\MetadataInterface
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Metadata, setValueElement) {

	zval *valueElement_param = NULL, *_0;
	zval *valueElement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &valueElement_param);

	if (unlikely(Z_TYPE_P(valueElement_param) != IS_STRING && Z_TYPE_P(valueElement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'valueElement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(valueElement_param) == IS_STRING)) {
		zephir_get_strval(valueElement, valueElement_param);
	} else {
		ZEPHIR_INIT_VAR(valueElement);
		ZVAL_EMPTY_STRING(valueElement);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, valueElement, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("valueElement"), _0 TSRMLS_CC);
	RETURN_THIS();

}

