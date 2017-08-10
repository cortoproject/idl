/* This is a managed file. Do not delete this comment. */

#include <corto/ext/idl/idl.h>

corto_type idl_Typedef_actualType(
    idl_Typedef this)
{
    corto_object result = this->type;

    while (corto_instanceof(idl_Typedef_o, result)) {
        result = idl_Typedef(result)->type;
    }

    return corto_type(result);
}

