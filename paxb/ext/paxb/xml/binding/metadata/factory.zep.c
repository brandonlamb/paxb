
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PAXB_Xml_Binding_Metadata_Factory) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Xml\\Binding\\Metadata, Factory, paxb, xml_binding_metadata_factory, paxb_xml_binding_metadata_factory_method_entry, 0);

	/**
	 * @var \PAXB\Xml\Binding\AnnotationLoader
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_factory_ce, SL("loader"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var \Doctrine\Common\Cache\Cache
	 */
	zend_declare_property_null(paxb_xml_binding_metadata_factory_ce, SL("cache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_string(paxb_xml_binding_metadata_factory_ce, SL("CACHE_PREFIX"), "PAXB_MD:" TSRMLS_CC);

	zend_class_implements(paxb_xml_binding_metadata_factory_ce TSRMLS_CC, 1, paxb_xml_binding_metadata_factoryinterface_ce);
	return SUCCESS;

}

/**
 * @param \PAXB\Xml\Binding\AnnotationLoader $loader
 * @param \Doctrine\Common\Cache\Cache $cache
 * @TODO Update type hint
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Factory, __construct) {

	zval *loader, *cache = NULL;

	zephir_fetch_params(0, 1, 1, &loader, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("loader"), loader TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("cache"), cache TSRMLS_CC);

}

/**
 * @param string $className
 * @return \PAXB\Xml\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Xml_Binding_Metadata_Factory, getMetadata) {

	zend_class_entry *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *className_param = NULL, *cacheKey, *metadata = NULL, *_1 = NULL, *_3, *_4, *_6, *_7;
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
	ZEPHIR_CALL_FUNCTION(&_1, "md5", &_2, className);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(cacheKey);
	ZEPHIR_CONCAT_SV(cacheKey, "PAXB_MD:", _1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("cache"), PH_NOISY_CC);
	if (Z_TYPE_P(_3) == IS_OBJECT) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&metadata, _4, "fetch", NULL, cacheKey);
		zephir_check_call_status();
		if (Z_TYPE_P(metadata) == IS_OBJECT) {
			if (zephir_instance_of_ev(metadata, paxb_xml_binding_metadata_metadatainterface_ce TSRMLS_CC)) {
				RETURN_CCTOR(metadata);
			}
		}
	}
	ZEPHIR_INIT_NVAR(metadata);
	_5 = zend_fetch_class(SL("PAXB\\Xml\\Binding\\Metadata\\Metadata"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(metadata, _5);
	if (zephir_has_constructor(metadata TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, metadata, "__construct", NULL, className);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _4, "processmetadata", NULL, metadata);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("cache"), PH_NOISY_CC);
	if (Z_TYPE_P(_6) == IS_OBJECT) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _7, "save", NULL, cacheKey, metadata);
		zephir_check_call_status();
	}
	RETURN_CCTOR(metadata);

}

