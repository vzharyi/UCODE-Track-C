#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL)
        return NULL;

    char *new_str = mx_strnew(mx_strlen(str));
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isspace(str[i])) {
            new_str[counter] = str[i];
            counter++;
        }
        if ((!mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            new_str[counter] = ' ';
            counter++;
        }
    }

    char *result = mx_strtrim(new_str);
    mx_strdel(&new_str);

    return result;
}
