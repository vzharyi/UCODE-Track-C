#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *tmp1 = (unsigned char *) dst;
    const unsigned char *tmp2 = (const unsigned char *) src;
    unsigned char stop = (unsigned char) c;

    for (size_t i = 0; i < n; i++) {
        tmp1[i] = tmp2[i];
        if (tmp2[i] == stop)
            return (void *) &tmp1[i + 1];
    }
    return NULL;
}
