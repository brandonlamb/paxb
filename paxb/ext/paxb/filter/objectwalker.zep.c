
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * Walks over the properties of an object applying the filters that were defined for them
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_ObjectWalker) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter, ObjectWalker, paxb, filter_objectwalker, paxb_filter_objectwalker_method_entry, 0);

	/**
	 * @var object
	 */
	zend_declare_property_null(paxb_filter_objectwalker_ce, SL("object"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \ReflectionClass
	 */
	zend_declare_property_null(paxb_filter_objectwalker_ce, SL("reflectionClass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var FilterLoaderInterface
	 */
	zend_declare_property_null(paxb_filter_objectwalker_ce, SL("filterLoader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param object $object
 * @param FilterLoaderInterface $filterLoader
 */
PHP_METHOD(PAXB_Filter_ObjectWalker, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *object, *filterLoader, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &object, &filterLoader);



	if (!(zephir_instance_of_ev(filterLoader, paxb_filter_loaderinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'filterLoader' must be an instance of 'PAXB\\\\Filter\\\\LoaderInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("object"), object TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, object);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("reflectionClass"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("filterLoader"), filterLoader TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies the selected rules to a property in the object
 *
 * @param string $property
 * @param array $filterRules
 */
PHP_METHOD(PAXB_Filter_ObjectWalker, applyFilterRules) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *filterRules = NULL;
	zval *property_param = NULL, *filterRules_param = NULL, *rule = NULL, **_2;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &property_param, &filterRules_param);

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
	if (!filterRules_param) {
		ZEPHIR_INIT_VAR(filterRules);
		array_init(filterRules);
	} else {
		zephir_get_arrval(filterRules, filterRules_param);
	}


	zephir_is_iterable(filterRules, &_1, &_0, 0, 0, "paxb/filter/objectwalker.zep", 55);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(rule, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "applyfilterrule", &_3, property, rule);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a Filtering Rule to a property
 *
 * @param string $property
 * @param \PAXB\Binding\Annotations\Filter\AnnotationInterface $filterRule
 *
 * @throws \UnexpectedValueException
 */
PHP_METHOD(PAXB_Filter_ObjectWalker, applyFilterRule) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *filterRule, *value = NULL, *filter = NULL, *filteredValue = NULL, *_0, *_2, *_3;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &filterRule);

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


	if (!(zephir_is_instance_of(filterRule, SL("PAXB\\Filter\\AnnotationInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'filterRule' must be an instance of 'PAXB\\\\Filter\\\\AnnotationInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("filterLoader"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_UnexpectedValueException, "A FilterLoader must be provided", "paxb/filter/objectwalker.zep", 70);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getpropertyvalue", &_1, property);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("filterLoader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&filter, _2, "getfilterforrule", NULL, filterRule);
	zephir_check_call_status();
	if (zephir_instance_of_ev(filter, paxb_filter_filters_objectawarefilter_ce TSRMLS_CC)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("object"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, filter, "setcurrentobject", NULL, _3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&filteredValue, filter, "apply", NULL, filterRule, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpropertyvalue", &_4, property, filteredValue);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieves the value of the property, overcoming visibility problems
 *
 * @param string $propertyName
 * @return mixed
 */
PHP_METHOD(PAXB_Filter_ObjectWalker, getPropertyValue) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *propertyName_param = NULL, *_0 = NULL, *_2;
	zval *propertyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName_param);

	if (unlikely(Z_TYPE_P(propertyName_param) != IS_STRING && Z_TYPE_P(propertyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(propertyName_param) == IS_STRING)) {
		zephir_get_strval(propertyName, propertyName_param);
	} else {
		ZEPHIR_INIT_VAR(propertyName);
		ZVAL_EMPTY_STRING(propertyName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getaccessiblereflectionproperty", &_1, propertyName);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("object"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getvalue", NULL, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Overrides the value of a property, overcoming visibility problems
 *
 * @param string $propertyName
 * @param mixed $value
 */
PHP_METHOD(PAXB_Filter_ObjectWalker, setPropertyValue) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *propertyName_param = NULL, *value, *_0 = NULL, *_2;
	zval *propertyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &propertyName_param, &value);

	if (unlikely(Z_TYPE_P(propertyName_param) != IS_STRING && Z_TYPE_P(propertyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(propertyName_param) == IS_STRING)) {
		zephir_get_strval(propertyName, propertyName_param);
	} else {
		ZEPHIR_INIT_VAR(propertyName);
		ZVAL_EMPTY_STRING(propertyName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getaccessiblereflectionproperty", &_1, propertyName);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("object"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setvalue", NULL, _2, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieves a property from the object and makes it visible
 *
 * @param string $propertyName
 * @return \ReflectionProperty
 */
PHP_METHOD(PAXB_Filter_ObjectWalker, getAccessibleReflectionProperty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *propertyName_param = NULL, *property = NULL, *_0, *_1;
	zval *propertyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName_param);

	if (unlikely(Z_TYPE_P(propertyName_param) != IS_STRING && Z_TYPE_P(propertyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(propertyName_param) == IS_STRING)) {
		zephir_get_strval(propertyName, propertyName_param);
	} else {
		ZEPHIR_INIT_VAR(propertyName);
		ZVAL_EMPTY_STRING(propertyName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("reflectionClass"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&property, _0, "getproperty", NULL, propertyName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, property, "setaccessible", NULL, _1);
	zephir_check_call_status();
	RETURN_CCTOR(property);

}

