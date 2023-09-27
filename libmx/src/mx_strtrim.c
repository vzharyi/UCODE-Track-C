#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    while (mx_isspace(*str))
        str++;
    int end = mx_strlen(str);
    while (mx_isspace(str[end - 1]))
        end--;
    return mx_strndup(str, end);
}
