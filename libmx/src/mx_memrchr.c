#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *tmp = (const unsigned char *) s;
    unsigned char stop = (unsigned char) c;
    for (size_t i = n; i > 0; i--) {
        if (tmp[i] == stop)
            return (void *) &tmp[i];
    }
    return NULL;
}
