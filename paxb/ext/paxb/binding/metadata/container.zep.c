
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_Container) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Binding\\Metadata, Container, paxb, binding_metadata_container, paxb_binding_metadata_container_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(paxb_binding_metadata_container_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array Metadata[]
 */
PHP_METHOD(PAXB_Binding_Metadata_Container, __construct) {

	zval *storage_param = NULL;
	zval *storage = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &storage_param);

	if (!storage_param) {
		ZEPHIR_INIT_VAR(storage);
		array_init(storage);
	} else {
		zephir_get_arrval(storage, storage_param);
	}


	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add a metadata object by classname
 *
 * @param string key
 * @param \PAXB\Binding\Metadata\MetadataInterface metadata
 * @return \PAXB\Binding\Metadata\Container
 */
PHP_METHOD(PAXB_Binding_Metadata_Container, set) {

	zval *key_param = NULL, *metadata;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &metadata);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	if (!(zephir_instance_of_ev(metadata, paxb_binding_metadata_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metadata' must be an instance of 'PAXB\\\\Binding\\\\Metadata\\\\MetadataInterface'", "", 0);
		return;
	}
	zephir_update_property_array(this_ptr, SL("storage"), key, metadata TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get a metadata object from container if it exists
 *
 * @param string key
 * return \PAXB\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Binding_Metadata_Container, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *metadata, *_0, *_1;
	zval *key = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_OBS_VAR(metadata);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&metadata, _0, key, 0 TSRMLS_CC)) {
		RETURN_CCTOR(metadata);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, paxb_binding_metadata_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SSV(_2, "Container:get", " - Container does not have ", key);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "paxb/binding/metadata/container.zep", 46 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Check if container has metadata for a class
 *
 * @param string key
 * return boolean
 */
PHP_METHOD(PAXB_Binding_Metadata_Container, has) {

	zval *key_param = NULL, *metadata, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&metadata, _0, key, 1 TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

