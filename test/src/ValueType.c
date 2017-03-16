/* $CORTO_GENERATED
 *
 * ValueType.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_ValueType_setup(
    test_ValueType this)
{
/* $begin(test/ValueType/setup) */

    this->p = idl_ParserCreate("idl/valuetype.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_ValueType_tc_attribute(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_attribute) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_interface i = corto_interface(foo);
    test_assert(i->members.length == 6);

    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m_1"));
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_int32_o));

    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_attributeEnum(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_attributeEnum) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_object e = corto_resolve(NULL, "Foo::Color");
    test_assert(e != NULL);
    test_assert(corto_typeof(e) == corto_type(corto_enum_o));
    test_assert(corto_checkState(e, CORTO_VALID));
    test_assert(corto_checkState(e, CORTO_DECLARED));
    test_assert(corto_checkState(e, CORTO_DEFINED));    

    corto_interface i = corto_interface(foo);
    test_assert(i->members.length == 6);

    test_assert(!strcmp(corto_idof(i->members.buffer[4]), "m_enum"));
    test_assert(corto_member(i->members.buffer[4])->type == corto_type(e));

    corto_release(e);
    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_attributeMulti(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_attributeMulti) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_interface i = corto_interface(foo);
    test_assert(i->members.length == 6);

    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "m_2"));
    test_assert(corto_member(i->members.buffer[1])->type == corto_type(corto_int32_o));

    test_assert(!strcmp(corto_idof(i->members.buffer[2]), "m_3"));
    test_assert(corto_member(i->members.buffer[2])->type == corto_type(corto_int32_o));

    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_attributeReadonly(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_attributeReadonly) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_interface i = corto_interface(foo);
    test_assert(i->members.length == 6);

    test_assert(!strcmp(corto_idof(i->members.buffer[3]), "m_readonly"));
    test_assert(corto_member(i->members.buffer[3])->type == corto_type(corto_string_o));
    test_assert(corto_member(i->members.buffer[3])->modifiers == CORTO_READONLY);

    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_attributeStruct(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_attributeStruct) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_object s = corto_resolve(NULL, "Foo::Nested");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));
    test_assert(corto_checkState(s, CORTO_VALID));
    test_assert(corto_checkState(s, CORTO_DECLARED));
    test_assert(corto_checkState(s, CORTO_DEFINED));    

    corto_interface i = corto_interface(foo);
    test_assert(i->members.length == 6);

    test_assert(!strcmp(corto_idof(i->members.buffer[5]), "m_struct"));
    test_assert(corto_member(i->members.buffer[5])->type == corto_type(s));

    corto_release(s);
    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_methodInParam(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_methodInParam) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_object m = corto_resolve(NULL, "Foo::inparam");
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(corto_method_o));
    test_assert(corto_checkState(m, CORTO_VALID));
    test_assert(corto_checkState(m, CORTO_DECLARED));
    test_assert(!corto_checkState(m, CORTO_DEFINED));

    corto_function f = corto_function(m);
    test_assert(f->parameters.length == 1);
    test_assert(!strcmp(f->parameters.buffer[0].name, "p"));
    test_assert(f->parameters.buffer[0].type == corto_type(foo));
    test_assert(!f->parameters.buffer[0].passByReference);
    test_assert(f->returnType == corto_type(corto_void_o));

    corto_release(m);
    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_methodOutParam(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_methodOutParam) */

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_class_o));
    test_assert(corto_checkState(foo, CORTO_VALID));
    test_assert(corto_checkState(foo, CORTO_DECLARED));
    test_assert(corto_checkState(foo, CORTO_DEFINED));

    corto_object m = corto_resolve(NULL, "Foo::outparam");
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(corto_method_o));
    test_assert(corto_checkState(m, CORTO_VALID));
    test_assert(corto_checkState(m, CORTO_DECLARED));
    test_assert(!corto_checkState(m, CORTO_DEFINED));

    corto_function f = corto_function(m);
    test_assert(f->parameters.length == 1);
    test_assert(!strcmp(f->parameters.buffer[0].name, "p"));
    test_assert(f->parameters.buffer[0].type == corto_type(foo));
    test_assert(!f->parameters.buffer[0].passByReference);
    test_assert(f->returnType == corto_type(corto_void_o));

    corto_release(m);
    corto_release(foo);

/* $end */
}

corto_void _test_ValueType_tc_methodOutParamNonRef(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_methodOutParamNonRef) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ValueType_tc_methodReturn(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_methodReturn) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ValueType_tc_methodTwoParams(
    test_ValueType this)
{
/* $begin(test/ValueType/tc_methodTwoParams) */

    /* << Insert implementation >> */

/* $end */
}
