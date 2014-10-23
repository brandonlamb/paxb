
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
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(PAXB_Binding_Annotations_AbstractLoader) {

	ZEPHIR_REGISTER_CLASS(PAXB\\Binding\\Annotations, AbstractLoader, paxb, binding_annotations_abstractloader, paxb_binding_annotations_abstractloader_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var \Doctrine\Common\Annotations\Reader
	 */
	zend_declare_property_null(paxb_binding_annotations_abstractloader_ce, SL("reader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Annotation loader constructor
 *
 * @param \Doctrine\Common\Annotations\Reader $reader
 * @param array $namespaces
 * @TODO Better way to load annotations?
 */
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, __construct) {

	zval *namespaces = NULL;
	zval *reader, *namespaces_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &reader, &namespaces_param);

	if (!namespaces_param) {
		ZEPHIR_INIT_VAR(namespaces);
		array_init(namespaces);
	} else {
		zephir_get_arrval(namespaces, namespaces_param);
	}


	zephir_update_property_this(this_ptr, SL("reader"), reader TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 */
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metadata);



	if (!(zephir_instance_of_ev(metadata, paxb_binding_metadata_metadatainterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'metadata' must be an instance of 'PAXB\\\\Binding\\\\Metadata\\\\MetadataInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processclassannotations", NULL, metadata);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processmethodannotations", NULL, metadata);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processpropertyannotations", NULL, metadata);
	zephir_check_call_status();
	RETVAL_ZVAL(metadata, 1, 0);
	RETURN_MM();

}

/**
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 * @throws \Doctrine\Common\Annotations\AnnotationException
 */
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processClassAnnotations) {

}

/**
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 * @throws \Doctrine\Common\Annotations\AnnotationException
 */
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processMethodAnnotations) {

}

/**
 * @param \PAXB\Binding\Metadata\MetadataInterface $metadata
 * @return \PAXB\Binding\Metadata\MetadataInterface
 * @throws \Doctrine\Common\Annotations\AnnotationException
 */
PHP_METHOD(PAXB_Binding_Annotations_AbstractLoader, processPropertyAnnotations) {

}

