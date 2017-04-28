/* $CORTO_GENERATED
 *
 * Parser.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ext/idl/idl.h>

int16_t _idl_Parser_construct(
    idl_Parser this)
{
/* $begin(corto/ext/idl/Parser/construct) */

    if (!this->source) {
        if (this->filename) {
            this->source = corto_fileLoad(this->filename);
            if (!this->source) {
                corto_seterr("idl: failed to load '%s'", this->filename);
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_struct _idl_Parser_declareStruct(
    idl_Parser this,
    corto_string name)
{
/* $begin(corto/ext/idl/Parser/declareStruct) */

    corto_struct result = corto_structDeclareChild(this->scope, name);
    corto_setref(&this->scope, result);
    corto_struct(result)->baseAccess = CORTO_PRIVATE;

    return result;
/* $end */
}

corto_union _idl_Parser_declareUnion(
    idl_Parser this,
    corto_string name,
    corto_type discriminator)
{
/* $begin(corto/ext/idl/Parser/declareUnion) */

    corto_union result = corto_unionDeclareChild(this->scope, name);
    corto_setref(&this->scope, result);
    corto_setref(result->discriminator, discriminator);

    return result;
/* $end */
}

corto_class _idl_Parser_declareValueType(
    idl_Parser this,
    corto_string name,
    idl_InheritanceSpec *inherits)
{
/* $begin(corto/ext/idl/Parser/declareValueType) */
    corto_interfaceseq seq = {0, NULL};

    if (inherits->supports && corto_llSize(inherits->supports)) {
        corto_uint32 i = 0;

        seq.length = corto_llSize(inherits->supports);
        seq.buffer = corto_alloc(sizeof(corto_interface) * seq.length);

        corto_iter it = corto_llIter(inherits->supports);
        while (corto_iterHasNext(&it)) {
            corto_type interface = corto_iterNext(&it);
            corto_setref(&seq.buffer[i++], interface);
        }
    }

    corto_class result = corto_classDeclareChild(this->scope, name);
    corto_setref(&corto_interface(result)->base, inherits->base);
    result->implements = seq;
    corto_setref(&this->scope, result);

    return result;
/* $end */
}

int16_t _idl_Parser_defineStruct(
    idl_Parser this,
    corto_struct s)
{
/* $begin(corto/ext/idl/Parser/defineStruct) */

    corto_setref(&this->scope, corto_parentof(this->scope));

    if (corto_define(s)) {
        corto_delete(s);
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _idl_Parser_defineUnion(
    idl_Parser this,
    corto_union u)
{
/* $begin(corto/ext/idl/Parser/defineUnion) */
    corto_setref(&this->scope, corto_parentof(this->scope));

    if (corto_define(u)) {
        corto_delete(u);
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _idl_Parser_defineValueType(
    idl_Parser this,
    corto_class v)
{
/* $begin(corto/ext/idl/Parser/defineValueType) */

    corto_setref(&this->scope, corto_parentof(this->scope));

    if (corto_define(v)) {
        corto_delete(v);
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _idl_Parser_parse(
    idl_Parser this)
{
/* $begin(corto/ext/idl/Parser/parse) */

    this->line = 1;
    corto_int16 idl_yparse(idl_Parser p);
    idl_yparse(this);

    return this->errors;
/* $end */
}

int16_t _idl_Parser_parseCase(
    idl_Parser this,
    corto_type type,
    idl_DeclaratorList name,
    corto_int32List discriminator)
{
/* $begin(corto/ext/idl/Parser/parseCase) */

    corto_iter it = corto_llIter(name);
    while (corto_iterHasNext(&it)) {
        idl_Declarator d = corto_iterNext(&it);

        corto_type t = idl_Declarator_getType(d, type);
        corto_case m = corto_caseDeclareChild(this->scope, d->identifier);

        corto_setref(&corto_member(m)->type, t);
        corto_member(m)->state = CORTO_DEFINED | CORTO_DECLARED;
        corto_member(m)->weak = FALSE;

        corto_iter dIt = corto_llIter(discriminator);
        while (corto_iterHasNext(&dIt)) {
            corto_int32 label = (corto_word)corto_iterNext(&it);
            corto_int32seqAppend(&m->discriminator, label);
        }

        if (corto_define(m)) {
            goto error;
        }

        corto_release(t);
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_enum _idl_Parser_parseEnum(
    idl_Parser this,
    corto_string name,
    corto_stringList enumerators)
{
/* $begin(corto/ext/idl/Parser/parseEnum) */

    corto_enum result = corto_enumDeclareChild(this->scope, name);

    corto_iter it = corto_llIter(enumerators);
    while (corto_iterHasNext(&it)) {
        corto_string e = corto_iterNext(&it);

        corto_constant *c = corto_constantDeclareChild(result, e);
        if (corto_define(c)) {
            corto_delete(result);
            goto error;
        }
    }

    if (corto_define(result)) {
        corto_delete(result);
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

int16_t _idl_Parser_parseMember(
    idl_Parser this,
    corto_type type,
    idl_DeclaratorList name,
    bool readonly)
{
/* $begin(corto/ext/idl/Parser/parseMember) */
     corto_modifier modifiers = CORTO_GLOBAL;

     if (readonly) {
        modifiers |= CORTO_READONLY;
     }

    corto_iter it = corto_llIter(name);
    while (corto_iterHasNext(&it)) {
        idl_Declarator d = corto_iterNext(&it);

        corto_type t = idl_Declarator_getType(d, type);
        idl_Member m = idl_MemberDeclareChild(this->scope, d->identifier);
        corto_type memberType = t;

        /* If type is optional, it must be a sequence<1>. Use elementType for
         * member, make the member optional and set the actualType to the
         * type provided in IDL */
        if (idl_annotateGetOptional(t)) {
            corto_type optionalType = idl_actualType(t);
            corto_assert(corto_instanceof(corto_sequence_o, optionalType), "optional type must be a sequence");
            corto_assert(corto_collection(optionalType)->max == 1, "optional sequence must have length one");
            corto_member(m)->modifiers |= CORTO_OPTIONAL;
            memberType = corto_collection(t)->elementType;
            corto_setref(&m->actualType, t);

        /* If type is typedef, unwind it for corto and set the actualType to
         * the typedef */
        } else if (corto_instanceof(idl_Typedef_o, t)) {
            memberType = idl_actualType(t);
            corto_setref(&m->actualType, t);
        }

        corto_setref(&corto_member(m)->type, memberType);
        corto_member(m)->modifiers |= modifiers;
        corto_member(m)->state = CORTO_DEFINED | CORTO_DECLARED;
        corto_member(m)->weak = FALSE;

        if (corto_define(m)) {
            goto error;
        }
        corto_release(t);
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _idl_Parser_parseMethod(
    idl_Parser this,
    corto_type returnType,
    corto_string name,
    corto_parameterList parameters)
{
/* $begin(corto/ext/idl/Parser/parseMethod) */
    corto_id sig;
    corto_method m = NULL;
    corto_uint32 i = 0;

    strcpy(sig, name);
    strcat(sig, "(");

    if (parameters && corto_llSize(parameters)) {
        corto_iter it = corto_llIter(parameters);
        while (corto_iterHasNext(&it)) {
            corto_parameter *p = corto_iterNext(&it);

            if (i) {
                strcat(sig, ",");
            }
            if (corto_parentof(p->type) == corto_lang_o) {
                strcat(sig, corto_idof(p->type));
            } else {
                corto_id paramType;
                corto_fullpath(paramType, p->type);
                strcat(sig, paramType);
            }
            if (p->passByReference && !p->type->reference) {
                strcat(sig, "&");
            }
            strcat(sig, " ");
            strcat(sig, p->name);
            i++;
        }
    }
    strcat(sig, ")");

    if (!(m = corto_methodDeclareChild(this->scope, sig))) {
        goto error;
    }

    corto_function(m)->kind = CORTO_PROCEDURE_STUB;
    corto_setref(&corto_function(m)->returnType, returnType);

    return 0;
error:
    return -1;
/* $end */
}

/* $header(corto/ext/idl/Parser/parsePragma) */
corto_int16 idl_Parser_parseKeylist(
    idl_Parser this)
{
    char *tok;
    corto_string typeName = strtok(NULL, " \n\t");
    if (!typeName) {
        corto_seterr("missing typename for #pragma keylist");
        goto error;
    }

    corto_object t = corto_lookup(this->scope, typeName);
    if (!t) {
        corto_seterr("type '%s' in #pragma keylist not found", typeName);
        goto error;
    }

    while ((tok = strtok(NULL, " \n\t"))) {
        corto_object m = corto_lookup(t, tok);
        if (!m) {
            corto_seterr("member '%s' in not found in type '%s'",
              tok, corto_fullpath(NULL, t));
            goto error;
        }

        if (!corto_instanceof(corto_member_o, m)) {
            corto_seterr("object '%s' in #pragma keylist is not a member",
              corto_fullpath(NULL, m));
            goto error;
        }

        corto_member(m)->modifiers |= CORTO_KEY;
    }

    return 0;
error:
    return -1;
}

corto_int16 idl_Parser_parseOptional(
    idl_Parser this)
{
    char *tok;
    while ((tok = strtok(NULL, " \n\t"))) {
        corto_object t = corto_lookup(this->scope, tok);
        if (!t) {
            corto_seterr("type '%s' in not found in scope '%s'",
              tok, corto_fullpath(NULL, this->scope));
            goto error;
        }

        if (!corto_instanceof(idl_Typedef_o, t) && !corto_instanceof(corto_type_o, t)) {
            corto_seterr("object '%s' in #pragma optional is not a type",
              corto_fullpath(NULL, t));
            goto error;
        }

        /* Keys are readonly */
        idl_annotateOptional(t, TRUE);
    }

    return 0;
error:
    return -1;
}
/* $end */
int16_t _idl_Parser_parsePragma(
    idl_Parser this,
    corto_string args)
{
/* $begin(corto/ext/idl/Parser/parsePragma) */
    char *tok;

    tok = strtok(args, " \n\t");
    if (!tok) {
        corto_seterr("parser error: invalid #pragma");
        goto error;
    }

    tok = strtok(NULL, " \n\t");
    if (!tok) {
        corto_seterr("missing directive for #pragma");
        goto error;
    }

    if (!strcmp(tok, "keylist")) {
        idl_Parser_parseKeylist(this);
    } else if (!strcmp(tok, "optional")){
        idl_Parser_parseOptional(this);
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_object _idl_Parser_parseTypedef(
    idl_Parser this,
    corto_type t,
    idl_DeclaratorList declarators)
{
/* $begin(corto/ext/idl/Parser/parseTypedef) */
    corto_object result = NULL;

    /* Only allow typedefs to primitives or non-scoped types */
    corto_iter it = corto_llIter(declarators);
    while (corto_iterHasNext(&it)) {
        idl_Declarator d = corto_iterNext(&it);

        corto_type declaratorType = idl_Declarator_getType(d, t);
        if (!declaratorType) {
            goto error;
        }
        if ((declaratorType->kind == CORTO_PRIMITIVE) || !corto_checkAttr(declaratorType, CORTO_ATTR_SCOPED)) {
            result = corto_declareChild(this->scope, d->identifier, corto_typeof(declaratorType));
            if (!result) {
                goto error;
            }
            corto_copy((corto_object*)&result, declaratorType);
            if (corto_define(result)) {
                goto error;
            }
            corto_release(declaratorType);
        } else {
            result = idl_TypedefCreateChild(this->scope, d->identifier, corto_typeof(declaratorType));
            if (!result) {
                goto error;
            }
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

void _idl_Parser_popModule(
    idl_Parser this)
{
/* $begin(corto/ext/idl/Parser/popModule) */

    corto_setref(&this->scope, corto_parentof(this->scope));

/* $end */
}

corto_package _idl_Parser_pushModule(
    idl_Parser this,
    corto_string name)
{
/* $begin(corto/ext/idl/Parser/pushModule) */

    corto_package p = corto_packageDeclareChild(this->scope, name);
    if (!p) {
        goto error;
    }
    if (corto_define(p)) {
        goto error;
    }

    corto_setref(&this->scope, p);

    return p;
error:
    return NULL;
/* $end */
}
