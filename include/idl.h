/* idl.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_EXT_IDL_H
#define CORTO_EXT_IDL_H

#include <corto/corto.h>
#include <corto/corto.h>
#include <corto/ext/idl/_project.h>
#include <corto/core/c/c.h>
#include <corto/lang/c/c.h>

/* $header() */
/* Enter additional code here. */
/* $end */

#include <corto/ext/idl/_type.h>
#include <corto/ext/idl/_load.h>
#include <corto/ext/idl/_api.h>

/* $body() */
/* Enter code that requires types here */
/* $end */

#ifdef __cplusplus
extern "C" {
#endif

#define idl_actualType(type) _idl_actualType(type)
CORTO_EXT_IDL_EXPORT
corto_type _idl_actualType(
    corto_object type);

#define idl_annotateActualType(o, t) _idl_annotateActualType(o, t)
CORTO_EXT_IDL_EXPORT
corto_void _idl_annotateActualType(
    corto_object o,
    corto_object t);

#define idl_annotateGetActualType(o) _idl_annotateGetActualType(o)
CORTO_EXT_IDL_EXPORT
corto_object _idl_annotateGetActualType(
    corto_object o);

#define idl_annotateGetOptional(o) _idl_annotateGetOptional(o)
CORTO_EXT_IDL_EXPORT
corto_bool _idl_annotateGetOptional(
    corto_object o);

#define idl_annotateOptional(o, optional) _idl_annotateOptional(o, optional)
CORTO_EXT_IDL_EXPORT
corto_void _idl_annotateOptional(
    corto_object o,
    corto_bool optional);

#include <corto/ext/idl/Declarator.h>
#include <corto/ext/idl/InheritanceSpec.h>
#include <corto/ext/idl/Member.h>
#include <corto/ext/idl/Parser.h>
#include <corto/ext/idl/Typedef.h>

#ifdef __cplusplus
}
#endif

#endif

