/* $CORTO_GENERATED
 *
 * Simple.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Simple_setup(
    test_Simple this)
{
/* $begin(test/Simple/setup) */

    this->p = idl_ParserCreate("idl/simple.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Simple_tc_point(
    test_Simple this)
{
/* $begin(test/Simple/tc_point) */

    corto_object s = corto_resolve(NULL, "Point");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 2);
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_int32_o));
    test_assert(corto_member(i->members.buffer[1])->type == corto_type(corto_int32_o));
    test_assert(corto_member(i->members.buffer[0])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[1])->modifiers == CORTO_GLOBAL);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "x"));
    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "y"));
    corto_release(s);

/* $end */
}

corto_void _test_Simple_tc_primitives(
    test_Simple this)
{
/* $begin(test/Simple/tc_primitives) */

    corto_object s = corto_resolve(NULL, "Primitives");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 9);
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_int16_o));
    test_assert(corto_member(i->members.buffer[1])->type == corto_type(corto_int32_o));
    test_assert(corto_member(i->members.buffer[2])->type == corto_type(corto_int64_o));
    test_assert(corto_member(i->members.buffer[3])->type == corto_type(corto_uint16_o));
    test_assert(corto_member(i->members.buffer[4])->type == corto_type(corto_uint32_o));
    test_assert(corto_member(i->members.buffer[5])->type == corto_type(corto_uint64_o));
    test_assert(corto_member(i->members.buffer[6])->type == corto_type(corto_float32_o));
    test_assert(corto_member(i->members.buffer[7])->type == corto_type(corto_float64_o));
    test_assert(corto_member(i->members.buffer[8])->type == corto_type(corto_string_o));
    test_assert(corto_member(i->members.buffer[0])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[1])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[2])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[3])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[4])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[5])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[6])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[7])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[8])->modifiers == CORTO_GLOBAL);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m_short"));
    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "m_long"));
    test_assert(!strcmp(corto_idof(i->members.buffer[2]), "m_longlong"));
    test_assert(!strcmp(corto_idof(i->members.buffer[3]), "m_ushort"));
    test_assert(!strcmp(corto_idof(i->members.buffer[4]), "m_ulong"));
    test_assert(!strcmp(corto_idof(i->members.buffer[5]), "m_ulonglong"));
    test_assert(!strcmp(corto_idof(i->members.buffer[6]), "m_float"));
    test_assert(!strcmp(corto_idof(i->members.buffer[7]), "m_double"));
    test_assert(!strcmp(corto_idof(i->members.buffer[8]), "m_string"));
    corto_release(s);

/* $end */
}
