/* $CORTO_GENERATED
 *
 * Nested.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Nested_setup(
    test_Nested this)
{
/* $begin(test/Nested/setup) */

    this->p = idl_ParserCreate("idl/nested.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Nested_tc_nestedStruct(
    test_Nested this)
{
/* $begin(test/Nested/tc_nestedStruct) */

    corto_object p = corto_resolve(NULL, "Parent");
    test_assert(p != NULL);
    test_assert(corto_typeof(p) == corto_type(corto_struct_o));

    corto_object n = corto_resolve(NULL, "Parent::NestedStruct");
    test_assert(n != NULL);
    test_assert(corto_typeof(n) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(p);
    test_assert(i->members.length == 2);
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_string_o));
    test_assert(corto_member(i->members.buffer[1])->type == corto_type(n));
    test_assert(corto_member(i->members.buffer[0])->modifiers == CORTO_GLOBAL);
    test_assert(corto_member(i->members.buffer[1])->modifiers == CORTO_GLOBAL);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m_1"));
    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "m_2"));
    corto_release(p);

    i = corto_interface(n);
    test_assert(i->members.length == 1);
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_string_o));
    test_assert(corto_member(i->members.buffer[0])->modifiers == CORTO_GLOBAL);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m"));
    corto_release(n);

/* $end */
}
