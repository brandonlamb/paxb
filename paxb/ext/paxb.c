
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "paxb.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *paxb_annotations_annotation_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlannotation_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlattribute_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlelement_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlelementwrapper_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlphpcollection_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlrootelement_ce;
zend_class_entry *paxb_xml_binding_annotations_xmltransient_ce;
zend_class_entry *paxb_xml_binding_annotations_xmlvalue_ce;

ZEND_DECLARE_MODULE_GLOBALS(paxb)

#define ZEPHIR_NUM_PREALLOCATED_FRAMES 25

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr TSRMLS_DC)
{
	zephir_memory_entry *start;
	size_t i;

	start = (zephir_memory_entry *) pecalloc(ZEPHIR_NUM_PREALLOCATED_FRAMES, sizeof(zephir_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;

#ifndef ZEPHIR_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 1].prev = &start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 2];

	for (i = 1; i < ZEPHIR_NUM_PREALLOCATED_FRAMES - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	zephir_globals_ptr->start_memory = start;
	zephir_globals_ptr->end_memory   = start + ZEPHIR_NUM_PREALLOCATED_FRAMES;

	zephir_globals_ptr->fcache = pemalloc(sizeof(HashTable), 1);
	zend_hash_init(zephir_globals_ptr->fcache, 128, NULL, NULL, 1); // zephir_fcall_cache_dtor

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_null);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_null, 2);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_false);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_false, 2);
	ZVAL_FALSE(zephir_globals_ptr->global_false);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_true);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_true, 2);
	ZVAL_TRUE(zephir_globals_ptr->global_true);

	//zephir_globals_ptr->initialized = 1;
}

int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**)pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[len - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef ZEPHIR_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

#ifndef ZEPHIR_RELEASE
	if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

#if PHP_VERSION_ID >= 50400
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	return ZEND_HASH_APPLY_KEEP;
}

void zephir_deinitialize_memory(TSRMLS_D)
{
	size_t i;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	//if (zephir_globals_ptr->initialized != 1) {
	//	zephir_globals_ptr->initialized = 0;
	//	return;
	//}

	if (zephir_globals_ptr->start_memory != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	//zephir_orm_destroy_cache(TSRMLS_C);

	zend_hash_apply_with_arguments(zephir_globals_ptr->fcache TSRMLS_CC, zephir_cleanup_fcache, 0);

#ifndef ZEPHIR_RELEASE
	assert(zephir_globals_ptr->start_memory != NULL);
#endif

	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		pefree(zephir_globals_ptr->start_memory[i].hash_addresses, 1);
		pefree(zephir_globals_ptr->start_memory[i].addresses, 1);
	}

	pefree(zephir_globals_ptr->start_memory, 1);
	zephir_globals_ptr->start_memory = NULL;

	zend_hash_destroy(zephir_globals_ptr->fcache);
	pefree(zephir_globals_ptr->fcache, 1);
	zephir_globals_ptr->fcache = NULL;

	for (i = 0; i < 2; i++) {
		zval_ptr_dtor(&zephir_globals_ptr->global_null);
		zval_ptr_dtor(&zephir_globals_ptr->global_false);
		zval_ptr_dtor(&zephir_globals_ptr->global_true);
	}

	//zephir_globals_ptr->initialized = 0;
}

static PHP_MINIT_FUNCTION(paxb)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(PAXB_Annotations_Annotation);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlAnnotation);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlAttribute);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlElement);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlElementWrapper);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlPhpCollection);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlRootElement);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlTransient);
	ZEPHIR_INIT(PAXB_Xml_Binding_Annotations_XmlValue);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(paxb)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_paxb_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
#if PHP_VERSION_ID < 50600
	zephir_globals->cache_enabled = 1;
#else
	zephir_globals->cache_enabled = 0;
#endif

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(paxb)
{

	zend_paxb_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(paxb)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(paxb)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PAXB_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PAXB_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PAXB_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PAXB_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PAXB_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(paxb)
{
	php_zephir_init_globals(paxb_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(paxb)
{

}

zend_module_entry paxb_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PAXB_EXTNAME,
	NULL,
	PHP_MINIT(paxb),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(paxb),
#else
	NULL,
#endif
	PHP_RINIT(paxb),
	PHP_RSHUTDOWN(paxb),
	PHP_MINFO(paxb),
	PHP_PAXB_VERSION,
	ZEND_MODULE_GLOBALS(paxb),
	PHP_GINIT(paxb),
	PHP_GSHUTDOWN(paxb),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PAXB
ZEND_GET_MODULE(paxb)
#endif
