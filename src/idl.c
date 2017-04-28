/* $CORTO_GENERATED
 *
 * idl.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ext/idl/idl.h>

/* $header() */
corto_threadKey IDL_PARSER_KEY;

/* Parse an IDL file */
int idl_loadFile(corto_string file, int argc, char* argv[], void* udata) {
    idl_Parser p;
    CORTO_UNUSED(udata);
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);

    /* Parse IDL */
    p = idl_ParserCreate(file, NULL);
    if (!p) {
        goto error;
    }
    
    idl_Parser_parse(p);
    corto_release(p);

    return 0;
error:
    return -1;
}

static corto_uint8 IDL_KEY_ANNOTATE;

typedef struct idl_annotation {
    corto_bool optional;
    corto_object actualType;
} idl_annotation;

static void idl_annotationFree(void *o) {
    corto_dealloc(o);
}

static idl_annotation* idl_annotationGet(corto_object o, corto_bool create) {
    idl_annotation *result = NULL;
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        result = corto_olsGet(o, IDL_KEY_ANNOTATE);
        if (!result && create) {
            result = corto_calloc(sizeof(idl_annotation));
            corto_olsSet(o, IDL_KEY_ANNOTATE, result);
        }
    }
    return result;
}
/* $end */

corto_type _idl_actualType(
    corto_object type)
{
/* $begin(corto/ext/idl/actualType) */
    corto_type result;

    if (corto_instanceof(idl_Typedef_o, type)) {
        result = idl_Typedef_actualType(type);
    } else {
        result = type;
    }

    return corto_type(result);
/* $end */
}

void _idl_annotateActualType(
    corto_object o,
    corto_object t)
{
/* $begin(corto/ext/idl/annotateActualType) */
    idl_annotation  *a = idl_annotationGet(o, TRUE);
    a->actualType = t;
/* $end */
}

corto_object _idl_annotateGetActualType(
    corto_object o)
{
/* $begin(corto/ext/idl/annotateGetActualType) */
    idl_annotation  *a = idl_annotationGet(o, FALSE);
    if (!a) {
        return NULL;
    }
    return a->actualType;
/* $end */
}

bool _idl_annotateGetOptional(
    corto_object o)
{
/* $begin(corto/ext/idl/annotateGetOptional) */
    idl_annotation  *a = idl_annotationGet(o, FALSE);
    if (!a) {
        return FALSE;
    }
    return a->optional;
/* $end */
}

void _idl_annotateOptional(
    corto_object o,
    bool optional)
{
/* $begin(corto/ext/idl/annotateOptional) */
    idl_annotation  *a = idl_annotationGet(o, TRUE);
    a->optional = optional;
/* $end */
}

int idlMain(int argc, char *argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);

    if (corto_threadTlsKey(&IDL_PARSER_KEY, NULL)) {
        return -1;
    }

    IDL_KEY_ANNOTATE = corto_olsKey(idl_annotationFree);

    /* Register corto extension */
    corto_loaderRegister("idl", idl_loadFile, NULL);

    return 0;
/* $end */
}
