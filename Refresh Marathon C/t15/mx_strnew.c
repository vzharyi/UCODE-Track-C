#include <stdlib.h>
#include <stddef.h>

char *mx_strnew(const int size) {
    if (size < 0)
        return NULL;
    char *str = (char *) malloc(size + 1);
    for (int i = 0; i < size + 1; i++)
        str[i] = '\0';
    return str;
}
