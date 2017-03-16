/* $CORTO_GENERATED
 *
 * Module.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Module_setup(
    test_Module this)
{
/* $begin(test/Module/setup) */

    this->p = idl_ParserCreate("idl/module.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Module_tc_module(
    test_Module this)
{
/* $begin(test/Module/tc_module) */

    corto_object m = corto_resolve(NULL, "MyModule");
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(corto_package_o));
    corto_release(m);

    corto_object s = corto_resolve(NULL, "MyModule::Foo");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 1);
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_int32_o));
    test_assert(corto_member(i->members.buffer[0])->modifiers == CORTO_GLOBAL);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m"));
    corto_release(s);

/* $end */
}

corto_void _test_Module_tc_nestedModule(
    test_Module this)
{
/* $begin(test/Module/tc_nestedModule) */

    corto_object m = corto_resolve(NULL, "MyModule::Nested");
    test_assert(m != NULL);
    test_assert(corto_typeof(m) == corto_type(corto_package_o));
    corto_release(m);

    corto_object s = corto_resolve(NULL, "MyModule::Nested::Bar");
    test_assert(s != NULL);
    test_assert(corto_typeof(s) == corto_type(corto_struct_o));

    corto_interface i = corto_interface(s);
    test_assert(i->members.length == 1);
    test_assert(corto_member(i->members.buffer[0])->type == corto_type(corto_string_o));
    test_assert(corto_member(i->members.buffer[0])->modifiers == CORTO_GLOBAL);
    test_assert(!strcmp(corto_idof(i->members.buffer[0]), "m"));
    corto_release(s);

/* $end */
}
