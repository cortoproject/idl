/* $CORTO_GENERATED
 *
 * Empty.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Empty_tc_empty(
    test_Empty this)
{
/* $begin(test/Empty/tc_empty) */

    this->p = idl_ParserCreate("idl/empty.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}
