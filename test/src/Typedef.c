/* $CORTO_GENERATED
 *
 * Typedef.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Typedef_setup(
    test_Typedef this)
{
/* $begin(test/Typedef/setup) */

    this->p = idl_ParserCreate("idl/typedef.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Typedef_tc_array(
    test_Typedef this)
{
/* $begin(test/Typedef/tc_array) */

    corto_object s = corto_resolve(NULL, "Typedefs");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object alias = corto_resolve(NULL, "stringArray");
    test_assert(alias != NULL);
    test_assert(corto_typeof(alias) == corto_type(corto_array_o));
    test_assert(corto_collection(alias)->elementType == corto_type(corto_string_o));
    test_assert(corto_collection(alias)->max == 6);

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 7);
    test_assert(!strcmp(corto_idof(i->members.buffer[5]), "m_6"));

    corto_type t = corto_member(i->members.buffer[5])->type;
    test_assert(t != NULL);
    test_assert(t == alias);

    corto_release(s);
    corto_release(alias);


/* $end */
}

corto_void _test_Typedef_tc_arrayOfStruct(
    test_Typedef this)
{
/* $begin(test/Typedef/tc_arrayOfStruct) */

    corto_object s = corto_resolve(NULL, "Typedefs");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object point = corto_resolve(NULL, "Point");
    test_assert(point != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object alias = corto_resolve(NULL, "pointArray");
    test_assert(alias != NULL);
    test_assert(corto_typeof(alias) == corto_type(corto_array_o));
    test_assert(corto_collection(alias)->elementType == corto_type(point));
    test_assert(corto_collection(alias)->max == 7);

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 7);
    test_assert(!strcmp(corto_idof(i->members.buffer[6]), "m_7"));

    corto_type t = corto_member(i->members.buffer[6])->type;
    test_assert(t != NULL);
    test_assert(t == alias);

    corto_release(s);
    corto_release(point);
    corto_release(alias);

/* $end */
}

corto_void _test_Typedef_tc_multiDeclarator(
    test_Typedef this)
{
/* $begin(test/Typedef/tc_multiDeclarator) */

    corto_object s = corto_resolve(NULL, "Typedefs");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object f32 = corto_resolve(NULL, "f32");
    test_assert(f32 != NULL);
    test_assert(corto_typeof(f32) == corto_type(corto_float_o));
    test_assert(corto_primitive(f32)->width == CORTO_WIDTH_32);

    corto_object real = corto_resolve(NULL, "real");
    test_assert(real != NULL);
    test_assert(corto_typeof(real) == corto_type(corto_float_o));
    test_assert(corto_primitive(real)->width == CORTO_WIDTH_32);

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 7);
    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "m_2"));
    test_assert(!strcmp(corto_idof(i->members.buffer[2]), "m_3"));

    corto_type t = corto_member(i->members.buffer[1])->type;
    test_assert(t == f32);

    t = corto_member(i->members.buffer[2])->type;
    test_assert(t == real);

    corto_release(s);
    corto_release(f32);
    corto_release(real);

/* $end */
}

corto_void _test_Typedef_tc_sequence(
    test_Typedef this)
{
/* $begin(test/Typedef/tc_sequence) */

    corto_object s = corto_resolve(NULL, "Typedefs");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object alias = corto_resolve(NULL, "realSeq");
    test_assert(alias != NULL);
    test_assert(corto_typeof(alias) == corto_type(corto_sequence_o));
    test_assert(corto_collection(alias)->max == 3);

    corto_object real = corto_resolve(NULL, "real");
    test_assert(real != NULL);
    test_assert(corto_collection(alias)->elementType == real);

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 7);
    test_assert(!strcmp(corto_idof(i->members.buffer[3]), "m_4"));

    corto_type t = corto_member(i->members.buffer[3])->type;
    test_assert(t != NULL);
    test_assert(t == alias);

    corto_release(s);
    corto_release(real);
    corto_release(alias);

/* $end */
}

corto_void _test_Typedef_tc_sequenceNested(
    test_Typedef this)
{
/* $begin(test/Typedef/tc_sequenceNested) */

    corto_object s = corto_resolve(NULL, "Typedefs");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object real = corto_resolve(NULL, "real");
    test_assert(real != NULL);

    corto_object alias = corto_resolve(NULL, "realSeqSeq");
    test_assert(alias != NULL);
    test_assert(corto_typeof(alias) == corto_type(corto_sequence_o));
    test_assert(corto_collection(alias)->max == 5);

    corto_type t = corto_collection(alias)->elementType;
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 4);
    test_assert(corto_collection(t)->elementType == corto_type(real));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 7);
    test_assert(!strcmp(corto_idof(i->members.buffer[4]), "m_5"));

    t = corto_member(i->members.buffer[4])->type;
    test_assert(t != NULL);
    test_assert(t == alias);

    corto_release(s);
    corto_release(real);
    corto_release(alias);

/* $end */
}

corto_void _test_Typedef_tc_simple(
    test_Typedef this)
{
/* $begin(test/Typedef/tc_simple) */

    corto_object s = corto_resolve(NULL, "Typedefs");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object alias = corto_resolve(NULL, "i32");
    test_assert(alias != NULL);
    test_assert(corto_typeof(alias) == corto_type(corto_int_o));
    test_assert(corto_primitive(alias)->width == CORTO_WIDTH_32);

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 7);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m_1"));

    corto_type t = corto_member(i->members.buffer[0])->type;
    test_assert(t != NULL);
    test_assert(t == alias);

    corto_release(s);
    corto_release(alias);

/* $end */
}
