
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


/**
 * Filter Object, responsible for retrieving the filtering rules
 * for the object and applying them
 */
/**
 * Class Filter
 *
 * Executor, receives objects that need filtering and executes attached rules.
 *
 * @package PAXB\Filter
 */
ZEPHIR_INIT_CLASS(PAXB_Filter_Filter) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Filter, Filter, paxb, filter_filter, paxb_filter_filter_method_entry, 0);

	/**
	 * @var \PAXB\Xml\Mapping\Metadata\FactoryInterface
	 */
	zend_declare_property_null(paxb_filter_filter_ce, SL("metadataFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var FilterLoaderInterface
	 */
	zend_declare_property_null(paxb_filter_filter_ce, SL("filterLoader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(paxb_filter_filter_ce TSRMLS_CC, 1, paxb_filter_filterinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param \PAXB\Binding\Metadata\FactoryInterface $metadataFactory
 * @param \PAXB\Filter\LoaderInterface $filterLoader
 */
PHP_METHOD(PAXB_Filter_Filter, __construct) {

	zval *metadataFactory, *filterLoader;

	zephir_fetch_params(0, 2, 0, &metadataFactory, &filterLoader);



	if (!(zephir_instance_of_ev(metadataFactory, paxb_binding_metadata_factoryinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'metadataFactory' must be an instance of 'PAXB\\\\Binding\\\\Metadata\\\\FactoryInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(filterLoader, paxb_filter_loaderinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'filterLoader' must be an instance of 'PAXB\\\\Filter\\\\LoaderInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("metadataFactory"), metadataFactory TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("filterLoader"), filterLoader TSRMLS_CC);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filter, filterEntity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *object;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &object);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "walkobject", NULL, object);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filter, filterProperty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property = NULL;
	zval *object, *property_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &object, &property_param);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "walkobject", NULL, object, property);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filter, filterValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *rule, *filter = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &rule);



	if (zephir_is_instance_of(rule, SL("PAXB\\Annotations\\Filter\\AnnotationInterface") TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("filterLoader"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&filter, _0, "getfilterforrule", NULL, rule);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(filter, "apply", NULL, rule, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "walkrulechain", NULL, value, rule);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(PAXB_Filter_Filter, getMetadataFactory) {


	RETURN_MEMBER(this_ptr, "metadataFactory");

}

/**
 * Iterates over annotated properties in an object filtering the selected
 * values
 *
 * @param object $object
 * @param string $limitProperty
 */
PHP_METHOD(PAXB_Filter_Filter, walkObject) {

	zephir_fcall_cache_entry *_8 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *limitProperty = NULL;
	zval *object, *limitProperty_param = NULL, *metadata = NULL, *walker, *property = NULL, *properties = NULL, *_0, *_1, *_2, *_3, **_6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &object, &limitProperty_param);

	if (!limitProperty_param) {
		ZEPHIR_INIT_VAR(limitProperty);
		ZVAL_EMPTY_STRING(limitProperty);
	} else {
	if (unlikely(Z_TYPE_P(limitProperty_param) != IS_STRING && Z_TYPE_P(limitProperty_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'limitProperty' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(limitProperty_param) == IS_STRING)) {
		zephir_get_strval(limitProperty, limitProperty_param);
	} else {
		ZEPHIR_INIT_VAR(limitProperty);
		ZVAL_EMPTY_STRING(limitProperty);
	}
	}


	if (Z_TYPE_P(object) == IS_NULL) {
		RETURN_MM_NULL();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("metadataFactory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, object, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&metadata, _0, "getmetadata", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(walker);
	object_init_ex(walker, paxb_filter_objectwalker_ce);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("filterLoader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, walker, "__construct", NULL, object, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_gettype(_3, limitProperty TSRMLS_CC);
	if (!ZEPHIR_IS_STRING_IDENTICAL(_3, "null")) {
		ZEPHIR_INIT_VAR(properties);
		array_init_size(properties, 2);
		zephir_array_fast_append(properties, limitProperty);
	} else {
		ZEPHIR_CALL_METHOD(&properties, metadata, "getfilteredproperties",  NULL);
		zephir_check_call_status();
	}
	zephir_is_iterable(properties, &_5, &_4, 0, 0, "paxb/filter/filter.zep", 108);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(property, _6);
		ZEPHIR_CALL_METHOD(&_7, metadata, "getpropertyrules", NULL, property);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, walker, "applyfilterrules", &_8, property, _7);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Iterates over an array of filters applying all to the value
 *
 * @param mixed $value
 * @param array $rules
 * @return mixed
 */
PHP_METHOD(PAXB_Filter_Filter, walkRuleChain) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *rules = NULL;
	zval *value, *rules_param = NULL, *rule = NULL, *filter = NULL, *newValue = NULL, **_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &rules_param);

	zephir_get_arrval(rules, rules_param);


	zephir_is_iterable(rules, &_1, &_0, 0, 0, "paxb/filter/filter.zep", 126);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(rule, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("filterLoader"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&filter, _3, "getfilterforrule", NULL, rule);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&newValue, filter, "apply", NULL, rule, value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(newValue);

}

