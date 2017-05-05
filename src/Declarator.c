/* $CORTO_GENERATED
 *
 * Declarator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ext/idl/idl.h>

corto_type _idl_Declarator_getType(
    idl_Declarator this,
    corto_type t)
{
/* $begin(corto/ext/idl/Declarator/getType) */
    corto_type result = t;

    if (this->arraySizes && corto_llSize(this->arraySizes)) {
        corto_iter it = corto_llIter(this->arraySizes);
        while (corto_iter_hasNext(&it)) {
            corto_uint32 s = (corto_word)corto_iter_next(&it);
            result = corto_type(corto_arrayCreate(result, s));
            if (!result) {
            	goto error;
            }
        }
    } else {
        corto_claim(result);
    }

    return result;
error:
	return NULL;
/* $end */
}
