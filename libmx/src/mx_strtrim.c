#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;
    int start = 0;
    int end = mx_strlen(str) - 1;
    char *temp = mx_strnew(mx_strlen(str));
    temp = mx_strncpy(temp, str, mx_strlen(str));
    while (mx_isspace(str[start]))
        start++;
    while (mx_isspace(str[end]))
        end--;
    char *result = mx_strnew(mx_strlen(str));
    int j = 0;
    for (int i = start; i <= end; i++) {
        result[j] = temp[i];
        j++;
    }
    mx_strdel(&temp);
    return result;
}
