/* This is a managed file. Do not delete this comment. */

#include <corto/ext/idl/idl.h>


corto_threadKey IDL_PARSER_KEY;

/* Parse an IDL file */
int idl_loadFile(corto_string file, int argc, char* argv[], void* ctx) {
    idl_Parser p;
    CORTO_UNUSED(ctx);
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
    if (corto_checkAttr(o, CORTO_ATTR_NAMED)) {
        result = corto_olsGet(o, IDL_KEY_ANNOTATE);
        if (!result && create) {
            result = corto_calloc(sizeof(idl_annotation));
            corto_olsSet(o, IDL_KEY_ANNOTATE, result);
        }
    }
    return result;
}

corto_type idl_actualType(
    corto_object type)
{
    corto_type result;

    if (corto_instanceof(idl_Typedef_o, type)) {
        result = idl_Typedef_actualType(type);
    } else {
        result = type;
    }

    return corto_type(result);
}

void idl_annotateActualType(
    corto_object o,
    corto_object t)
{
    idl_annotation  *a = idl_annotationGet(o, TRUE);
    a->actualType = t;
}

corto_object idl_annotateGetActualType(
    corto_object o)
{
    idl_annotation  *a = idl_annotationGet(o, FALSE);
    if (!a) {
        return NULL;
    }
    return a->actualType;
}

bool idl_annotateGetOptional(
    corto_object o)
{
    idl_annotation  *a = idl_annotationGet(o, FALSE);
    if (!a) {
        return FALSE;
    }
    return a->optional;
}

void idl_annotateOptional(
    corto_object o,
    bool optional)
{
    idl_annotation  *a = idl_annotationGet(o, TRUE);
    a->optional = optional;
}

int idlMain(int argc, char *argv[]) {
    /* Insert code that must be run when component is loaded */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);

    if (corto_threadTlsKey(&IDL_PARSER_KEY, NULL)) {
        return -1;
    }

    IDL_KEY_ANNOTATE = corto_olsKey(idl_annotationFree);

    /* Register corto extension */
    corto_load_register("idl", idl_loadFile, NULL);

    return 0;
}

