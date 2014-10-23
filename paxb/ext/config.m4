PHP_ARG_ENABLE(paxb, whether to enable paxb, [ --enable-paxb   Enable Paxb])

if test "$PHP_PAXB" = "yes"; then
	AC_DEFINE(HAVE_PAXB, 1, [Whether you have Paxb])
	paxb_sources="paxb.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c paxb/binding/annotations/abstractloader.zep.c
	paxb/binding/annotations/annotation.zep.c
	paxb/binding/annotations/exception.zep.c
	paxb/binding/annotations/filter/annotationinterface.zep.c
	paxb/binding/annotations/loaderinterface.zep.c
	paxb/binding/annotations/xml/annotationinterface.zep.c
	paxb/binding/metadata/container.zep.c
	paxb/binding/metadata/exception.zep.c
	paxb/binding/metadata/factory.zep.c
	paxb/binding/metadata/factoryinterface.zep.c
	paxb/binding/metadata/metadata.zep.c
	paxb/binding/metadata/metadatainterface.zep.c
	paxb/binding/structure/abstractstructure.zep.c
	paxb/binding/structure/structureinterface.zep.c
	paxb/filter/exception/filterexception.zep.c
	paxb/filter/exception/invalidcallbackexception.zep.c
	paxb/filter/exception/invalidoptionsexception.zep.c
	paxb/filter/exception/invalidzendfilterexception.zep.c
	paxb/filter/exception/missingoptionsexception.zep.c
	paxb/filter/exception/ruledefinitionexception.zep.c
	paxb/filter/exception/ruleoptionsexception.zep.c
	paxb/filter/filter.zep.c
	paxb/filter/filterinterface.zep.c
	paxb/filter/filters/alpha.zep.c
	paxb/filter/filters/alphanumeric.zep.c
	paxb/filter/filters/digits.zep.c
	paxb/filter/filters/filterinterface.zep.c
	paxb/filter/filters/htmlentities.zep.c
	paxb/filter/filters/integer.zep.c
	paxb/filter/filters/objectawarefilter.zep.c
	paxb/filter/filters/pregreplace.zep.c
	paxb/filter/filters/regexp.zep.c
	paxb/filter/filters/stripnewlines.zep.c
	paxb/filter/filters/striptags.zep.c
	paxb/filter/filters/tolower.zep.c
	paxb/filter/filters/trim.zep.c
	paxb/filter/filters/zend.zep.c
	paxb/filter/loader.zep.c
	paxb/filter/loaderinterface.zep.c
	paxb/filter/objectwalker.zep.c
	paxb/xml/binding/structure/attribute.zep.c
	paxb/xml/binding/structure/element.zep.c "
	PHP_NEW_EXTENSION(paxb, $paxb_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([paxb], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([paxb], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS
fi
