/* $CORTO_GENERATED
 *
 * Typedef.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ext/idl/idl.h>

corto_type _idl_Typedef_actualType(
    idl_Typedef this)
{
/* $begin(corto/ext/idl/Typedef/actualType) */
    corto_object result = this->type;

    while (corto_instanceof(idl_Typedef_o, result)) {
        result = idl_Typedef(result)->type;
    }

    return corto_type(result);
/* $end */
}
