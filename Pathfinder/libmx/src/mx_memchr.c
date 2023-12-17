#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = (unsigned char *) s;
    unsigned char stop = (unsigned char) c;

    for (size_t i = 0; i < n; i++) {
        if (ptr[i] == stop)
            return (void *) (ptr + i);
    }
    return NULL;
}
