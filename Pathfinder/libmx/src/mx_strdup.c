#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *temp = mx_strnew(mx_strlen(s1));
    mx_strcpy(temp, s1);
    return temp;
}
