#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        (*count)++;
        int midd = (right + left) / 2;
        if (mx_strcmp(arr[midd], s) == 0)
            return midd;
        else if (mx_strcmp(arr[midd], s) > 0)
            right = midd - 1;
        else
            left = midd + 1;
    }
    *count = 0;
    return -1;
}
