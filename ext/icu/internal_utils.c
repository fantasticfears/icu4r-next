#include "icu.h"

VALUE icu_enum_to_rb_ary(UEnumeration* icu_enum, UErrorCode status, long pre_allocated)
{
    if (U_FAILURE(status)) {
        uenum_close(icu_enum);
        rb_raise(rb_eICU_Error, u_errorName(status));
    }
    VALUE result = rb_ary_new2(pre_allocated);
    UChar* ptr = NULL;
    int32_t len = 0;
    status = U_ZERO_ERROR;
    while ((ptr = uenum_unext(icu_enum, &len, &status)) != NULL) {
        if (U_FAILURE(status)) {
            uenum_close(icu_enum);
            rb_raise(rb_eICU_Error, u_errorName(status));
        }
        VALUE s = icu_ustring_from_uchar_str(ptr, len);
        rb_ary_push(result, icu_ustring_to_rb_enc_str(s));
        icu_ustring_clear_ptr(s);
        status = U_ZERO_ERROR;
    }
    uenum_close(icu_enum);
    return result;
}