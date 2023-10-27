#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 1 || buf_size > 2147483647 || fd <= 0 || lineptr == NULL)
        return -2;

    size_t bytes = 0;
    size_t line_size = buf_size;
    char buf;
    *lineptr = (char *) malloc(line_size);
    while (read(fd, &buf, 1) > 0) {
        if (buf == delim)
            break;
        (*lineptr)[bytes] = buf;
        bytes++;
        if (bytes >= line_size) {
            line_size *= 2;
            char *temp = (char *) mx_realloc(*lineptr, line_size);
            if (temp == NULL) {
                free(*lineptr);
                return -1;
            }
            *lineptr = temp;
        }
    }
    (*lineptr)[bytes] = '\0';

    if (read(fd, &buf, 1) < 0) {
        free(*lineptr);
        return -1;
    }

    return bytes;
}
