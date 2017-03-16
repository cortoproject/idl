/* $CORTO_GENERATED
 *
 * Array.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Array_setup(
    test_Array this)
{
/* $begin(test/Array/setup) */

    this->p = idl_ParserCreate("idl/array.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Array_tc_array(
    test_Array this)
{
/* $begin(test/Array/tc_array) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m_1"));

    corto_type t = corto_member(i->members.buffer[0])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));

    corto_array a = corto_array(t);
    test_assert(a->elementType == corto_type(corto_int32_o));
    test_assert(corto_collection(a)->max == 3);

    corto_release(s);

/* $end */
}

corto_void _test_Array_tc_arrayDouble(
    test_Array this)
{
/* $begin(test/Array/tc_arrayDouble) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "m_2"));

    corto_type t = corto_member(i->members.buffer[1])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));

    corto_array a = corto_array(t);
    test_assert(corto_collection(a)->max == 5);
    test_assert(corto_typeof(a->elementType) == corto_type(corto_array_o));
    test_assert(corto_collection(a->elementType)->elementType == corto_type(corto_int32_o));
    test_assert(corto_collection(a->elementType)->max == 4);

    corto_release(s);

/* $end */
}

corto_void _test_Array_tc_arrayMultiple(
    test_Array this)
{
/* $begin(test/Array/tc_arrayMultiple) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[2]), "m_3"));
    test_assert(!strcmp(corto_idof(i->members.buffer[3]), "m_4"));

    corto_type t = corto_member(i->members.buffer[2])->type;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    t = corto_member(i->members.buffer[3])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 6);

    t = corto_collection(t)->elementType;
    test_assert(t == corto_type(corto_int32_o));

    corto_release(s);

/* $end */
}

corto_void _test_Array_tc_arrayMultipleDouble(
    test_Array this)
{
/* $begin(test/Array/tc_arrayMultipleDouble) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[4]), "m_5"));
    test_assert(!strcmp(corto_idof(i->members.buffer[5]), "m_6"));

    corto_type t = corto_member(i->members.buffer[4])->type;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    t = corto_member(i->members.buffer[5])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 8);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 7);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    corto_release(s);

/* $end */
}

corto_void _test_Array_tc_arrayMultipleNestedTriple(
    test_Array this)
{
/* $begin(test/Array/tc_arrayMultipleNestedTriple) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object n = corto_resolve(NULL, "Arrays::Point");
    test_assert(n != NULL);
    test_assert(corto_typeof(n) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[10]), "m_11"));
    test_assert(!strcmp(corto_idof(i->members.buffer[11]), "m_12"));
    test_assert(!strcmp(corto_idof(i->members.buffer[12]), "m_13"));

    corto_type t = corto_member(i->members.buffer[10])->type;
    test_assert(t != NULL);
    test_assert(t == corto_type(n));

    t = corto_member(i->members.buffer[11])->type;
    test_assert(t != NULL);
    test_assert(t == corto_type(n));

    t = corto_member(i->members.buffer[12])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 17);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 16);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 15);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == n);

/* $end */
}

corto_void _test_Array_tc_arrayMultipleTriple(
    test_Array this)
{
/* $begin(test/Array/tc_arrayMultipleTriple) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[7]), "m_8"));
    test_assert(!strcmp(corto_idof(i->members.buffer[8]), "m_9"));
    test_assert(!strcmp(corto_idof(i->members.buffer[9]), "m_10"));

    corto_type t = corto_member(i->members.buffer[7])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 12);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    t = corto_member(i->members.buffer[8])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 13);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    t = corto_member(i->members.buffer[9])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 16);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 15);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 14);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    corto_release(s);

/* $end */
}

corto_void _test_Array_tc_arrayTriple(
    test_Array this)
{
/* $begin(test/Array/tc_arrayTriple) */

    corto_object s = corto_resolve(NULL, "Arrays");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 13);
    test_assert(!strcmp(corto_idof(i->members.buffer[6]), "m_7"));

    corto_type t = corto_member(i->members.buffer[6])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 11);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 10);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_array_o));
    test_assert(corto_collection(t)->max == 9);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

    corto_release(s);

/* $end */
}
