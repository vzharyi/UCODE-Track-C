#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 1 || buf_size > 2147483647 || fd <= 0 || lineptr == NULL) {
        return -2;
    }

    char *str = NULL;
    size_t size_result = 0;
    char buf;
    ssize_t n_read;

    *lineptr = mx_strnew(0);

    while ((n_read = read(fd, &buf, 1)) == 1) {
        if (buf == delim) {
            break;
        }

        char temp_buf[2];
        temp_buf[0] = buf;
        temp_buf[1] = '\0';

        char *temp_ptr = str;
        str = mx_strjoin(str, temp_buf);
        mx_strdel(&temp_ptr);

        size_result++;
    }

    if (n_read == -1) {
        mx_strdel(&str);
        return -2;
    }

    if (size_result == 0 && n_read == 0) {
        return -1;
    }

    *lineptr = str;
    return size_result;
}
