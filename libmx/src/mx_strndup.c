#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t length = mx_strlen(s1);
    if (n < length)
        length = n;
    char *dup = NULL;
    dup = mx_strnew(length);
    if (dup != NULL) {
        mx_strncpy(dup, s1, length);
        dup[length] = '\0';
    }
    return dup;
}
