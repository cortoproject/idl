/* $CORTO_GENERATED
 *
 * Comments.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Comments_tc_comments(
    test_Comments this)
{
/* $begin(test/Comments/tc_comments) */

    this->p = idl_ParserCreate("idl/comments.idl", NULL);
    test_assert(this->p != NULL);
    corto_int16 ret = idl_Parser_parse(this->p);
    test_assert(ret == 0);

/* $end */
}
