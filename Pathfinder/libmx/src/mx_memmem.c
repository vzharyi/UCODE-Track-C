#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len <= 0 || little_len <= 0 || big_len < little_len)
        return NULL;
    const unsigned char *tmp1 = (const unsigned char *) big;
    const unsigned char *tmp2 = (const unsigned char *) little;
    for (size_t i = 0; i <= big_len - little_len ; i++) {
        if (mx_memcmp(tmp1 + i, tmp2, little_len) == 0)
            return (void *) (tmp1 + i);
    }
    return NULL;
}
