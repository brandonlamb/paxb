
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PAXB_H
#define PHP_PAXB_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_PAXB_NAME        "paxb"
#define PHP_PAXB_VERSION     "0.0.1"
#define PHP_PAXB_EXTNAME     "paxb"
#define PHP_PAXB_AUTHOR      ""
#define PHP_PAXB_ZEPVERSION  "0.5.4a"
#define PHP_PAXB_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(paxb)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(paxb)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(paxb)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(paxb_globals_id, zend_paxb_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (paxb_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_paxb_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(paxb_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(paxb_globals)
#endif

#define zephir_globals_def paxb_globals
#define zend_zephir_globals_def zend_paxb_globals

extern zend_module_entry paxb_module_entry;
#define phpext_paxb_ptr &paxb_module_entry

#endif
