#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t size_ptr;
    size_ptr = malloc_size(ptr);
    if (ptr == 0)
        return malloc(size);
    if (size <= size_ptr)
        return ptr;
    void *new_ptr = malloc(size);
    mx_memcpy(new_ptr, ptr, size_ptr);
    free(ptr);
    return new_ptr;
}
