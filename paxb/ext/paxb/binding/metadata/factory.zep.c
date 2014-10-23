
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(PAXB_Binding_Metadata_Factory) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Binding\\Metadata, Factory, paxb, binding_metadata_factory, paxb_binding_metadata_factory_method_entry, 0);

	/**
	 * @var \PAXB\Binding\Annotations\Loader
	 */
	zend_declare_property_null(paxb_binding_metadata_factory_ce, SL("loader"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var \PAXB\Binding\Metadata\Container
	 */
	zend_declare_property_null(paxb_binding_metadata_factory_ce, SL("container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var \Doctrine\Common\Cache\Cache
	 */
	zend_declare_property_null(paxb_binding_metadata_factory_ce, SL("cache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_string(paxb_binding_metadata_factory_ce, SL("CACHE_PREFIX"), "PAXB_MD:" TSRMLS_CC);

	zend_class_implements(paxb_binding_metadata_factory_ce TSRMLS_CC, 1, paxb_binding_metadata_factoryinterface_ce);
	return SUCCESS;

}

/**
 * @param \PAXB\Binding\Annotations\Loader $loader
 * @param \Doctrine\Common\Cache\Cache $cache
 * @TODO Update type hint
 */
PHP_METHOD(PAXB_Binding_Metadata_Factory, __construct) {

	zval *loader, *container, *cache = NULL;

	zephir_fetch_params(0, 2, 1, &loader, &container, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(container, paxb_binding_metadata_container_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'container' must be an instance of 'PAXB\\\\Binding\\\\Metadata\\\\Container'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("loader"), loader TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("container"), container TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("cache"), cache TSRMLS_CC);

}

/**
 * @param string $className
 * @return \PAXB\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Binding_Metadata_Factory, getMetadata) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *cacheKey, *metadata = NULL, *_1, *_2 = NULL, *_3, *_4 = NULL, *_6, *_7, *_8;
	zval *className = NULL, *_0;

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


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SSVS(_0, "Factory:getMetadata", ": ", className, "\n");
	zend_print_zval(_0, 0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "has", NULL, className);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(_2)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_3, "get", NULL, className);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_4, "md5", &_5, className);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(cacheKey);
	ZEPHIR_CONCAT_SV(cacheKey, "PAXB_MD:", _4);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("cache"), PH_NOISY_CC);
	if (Z_TYPE_P(_6) == IS_OBJECT) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&metadata, _3, "fetch", NULL, cacheKey);
		zephir_check_call_status();
		if (Z_TYPE_P(metadata) == IS_OBJECT) {
			if (zephir_instance_of_ev(metadata, paxb_binding_metadata_metadatainterface_ce TSRMLS_CC)) {
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _7, "set", NULL, className, metadata);
				zephir_check_call_status();
				RETURN_CCTOR(metadata);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&metadata, this_ptr, "parsemetadata", NULL, className);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, className, metadata);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property_this(&_8, this_ptr, SL("cache"), PH_NOISY_CC);
	if (Z_TYPE_P(_8) == IS_OBJECT) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _7, "save", NULL, cacheKey, metadata);
		zephir_check_call_status();
	}
	RETURN_CCTOR(metadata);

}

/**
 * @param string $className
 * @return \PAXB\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Binding_Metadata_Factory, parseMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *metadata, *_0;
	zval *className = NULL;

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


	ZEPHIR_INIT_VAR(metadata);
	object_init_ex(metadata, paxb_binding_metadata_metadata_ce);
	ZEPHIR_CALL_METHOD(NULL, metadata, "__construct", NULL, className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadparentmetadata", NULL, metadata);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadinterfacemetadata", NULL, metadata);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "processmetadata", NULL, metadata);
	zephir_check_call_status();
	RETURN_CCTOR(metadata);

}

/**
 * Checks if the class being parsed has a parent and cascades parsing
 * to its parent
 *
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Binding_Metadata_Factory, loadParentMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata, *parentClass = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metadata);



	if (!(zephir_instance_of_ev(metadata, paxb_binding_metadata_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metadata' must be an instance of 'PAXB\\\\Binding\\\\Metadata\\\\MetadataInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, metadata, "getreflectionclass",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&parentClass, _0, "getparentclass",  NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(parentClass) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2, parentClass, "getname",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmetadata", NULL, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, metadata, "mergerules", NULL, _1);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(metadata, 1, 0);
	RETURN_MM();

}

/**
 * Checks if the object has interfaces and cascades parsing of annotatiosn
 * to all the interfaces
 *
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Binding_Metadata_Factory, loadInterfaceMetadata) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata, *interfaces = NULL, *interface = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metadata);



	if (!(zephir_instance_of_ev(metadata, paxb_binding_metadata_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metadata' must be an instance of 'PAXB\\\\Binding\\\\Metadata\\\\MetadataInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, metadata, "getreflectionclass",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&interfaces, _0, "getinterfaces",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(interfaces, &_2, &_1, 0, 0, "paxb/binding/metadata/factory.zep", 134);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(interface, _3);
		ZEPHIR_CALL_METHOD(&_5, interface, "getname",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getmetadata", &_6, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, metadata, "mergerules", NULL, _4);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(metadata, 1, 0);
	RETURN_MM();

}

