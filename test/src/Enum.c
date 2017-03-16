/* $CORTO_GENERATED
 *
 * Enum.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Enum_setup(
    test_Enum this)
{
/* $begin(test/Enum/setup) */

    this->p = idl_ParserCreate("idl/enum.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_Enum_tc_enum(
    test_Enum this)
{
/* $begin(test/Enum/tc_enum) */

    corto_object e = corto_resolve(NULL, "Color");
    test_assert(e != NULL);
    test_assert(corto_typeof(e) == corto_type(corto_enum_o));

    corto_object red = corto_resolve(NULL, "Color::Red");
    test_assert(corto_typeof(red) == corto_type(corto_constant_o));
    test_assert(*(corto_constant*)red == 0);

    corto_object orange = corto_resolve(NULL, "Color::Orange");
    test_assert(corto_typeof(orange) == corto_type(corto_constant_o));
    test_assert(*(corto_constant*)orange == 1);

    corto_object yellow = corto_resolve(NULL, "Color::Yellow");
    test_assert(corto_typeof(yellow) == corto_type(corto_constant_o));
    test_assert(*(corto_constant*)yellow == 2);

    corto_object green = corto_resolve(NULL, "Color::Green");
    test_assert(corto_typeof(green) == corto_type(corto_constant_o));
    test_assert(*(corto_constant*)green == 3);

    corto_object blue = corto_resolve(NULL, "Color::Blue");
    test_assert(corto_typeof(blue) == corto_type(corto_constant_o));
    test_assert(*(corto_constant*)blue == 4);

    corto_object purple = corto_resolve(NULL, "Color::Purple");
    test_assert(corto_typeof(purple) == corto_type(corto_constant_o));
    test_assert(*(corto_constant*)purple == 5);

    test_assert(corto_enum(e)->constants.length == 6);
    test_assert(corto_enum(e)->constants.buffer[0] == red);
    test_assert(corto_enum(e)->constants.buffer[1] == orange);
    test_assert(corto_enum(e)->constants.buffer[2] == yellow);
    test_assert(corto_enum(e)->constants.buffer[3] == green);
    test_assert(corto_enum(e)->constants.buffer[4] == blue);
    test_assert(corto_enum(e)->constants.buffer[5] == purple);

    corto_release(red);
    corto_release(orange);
    corto_release(yellow);
    corto_release(green);
    corto_release(blue);
    corto_release(purple);
    corto_release(e);

/* $end */
}
