/* This is a managed file. Do not delete this comment. */

#include <driver/ext/idl/idl.h>

corto_type idl_Declarator_getType(
    idl_Declarator this,
    corto_type t)
{
    corto_type result = t;

    if (this->arraySizes && corto_ll_size(this->arraySizes)) {
        corto_iter it = corto_ll_iter(this->arraySizes);
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
}

