/* $CORTO_GENERATED
 *
 * Sequence.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Sequence_setup(
    test_Sequence this)
{
/* $begin(test/Sequence/setup) */

    this->p = idl_ParserCreate("idl/sequence.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Sequence_tc_sequence(
    test_Sequence this)
{
/* $begin(test/Sequence/tc_sequence) */

    corto_object s = corto_resolve(NULL, "Sequences");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 5);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m_1"));

    corto_type t = corto_member(i->members.buffer[0])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 0);

    t = corto_collection(t)->elementType;
    test_assert(t == corto_type(corto_int32_o));

/* $end */
}

corto_void _test_Sequence_tc_sequenceMax(
    test_Sequence this)
{
/* $begin(test/Sequence/tc_sequenceMax) */

    corto_object s = corto_resolve(NULL, "Sequences");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 5);
    test_assert(!strcmp(corto_idof(i->members.buffer[1]), "m_2"));

    corto_type t = corto_member(i->members.buffer[1])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 3);

    t = corto_collection(t)->elementType;
    test_assert(t == corto_type(corto_int32_o));

/* $end */
}

corto_void _test_Sequence_tc_sequenceNested(
    test_Sequence this)
{
/* $begin(test/Sequence/tc_sequenceNested) */

    corto_object s = corto_resolve(NULL, "Sequences");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 5);
    test_assert(!strcmp(corto_idof(i->members.buffer[4]), "m_5"));

    corto_type t = corto_member(i->members.buffer[4])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 7);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 6);

    t = corto_collection(t)->elementType;
    test_assert(t != NULL);
    test_assert(t == corto_type(corto_int32_o));

/* $end */
}

corto_void _test_Sequence_tc_sequenceStruct(
    test_Sequence this)
{
/* $begin(test/Sequence/tc_sequenceStruct) */

    corto_object s = corto_resolve(NULL, "Sequences");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object foo = corto_resolve(NULL, "Foo");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 5);
    test_assert(!strcmp(corto_idof(i->members.buffer[2]), "m_3"));

    corto_type t = corto_member(i->members.buffer[2])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 4);

    t = corto_collection(t)->elementType;
    test_assert(t == corto_type(foo));

/* $end */
}

corto_void _test_Sequence_tc_sequenceStructNested(
    test_Sequence this)
{
/* $begin(test/Sequence/tc_sequenceStructNested) */

    corto_object s = corto_resolve(NULL, "Sequences");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_object foo = corto_resolve(NULL, "Foo::Nested");
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 5);
    test_assert(!strcmp(corto_idof(i->members.buffer[3]), "m_4"));

    corto_type t = corto_member(i->members.buffer[3])->type;
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_sequence_o));
    test_assert(corto_collection(t)->max == 5);

    t = corto_collection(t)->elementType;
    test_assert(t == corto_type(foo));

/* $end */
}
