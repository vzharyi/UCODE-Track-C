#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return  -2;

    if (mx_strlen(sub) == 0)
        return -1;

    for (int i = 0; i < mx_strlen(str) - mx_strlen(sub); i++) {
        if (mx_strncmp(str + i, sub, mx_strlen(sub)) == 0)
            return i;
    }
    return -1;
}
