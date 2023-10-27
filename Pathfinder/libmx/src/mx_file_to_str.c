#include "libmx.h"

char *mx_file_to_str(const char *filename) {
	if (filename == NULL)
		return NULL;
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
		return NULL;
	int size = 0;
	char ch;
	while(read(fd, &ch, 1) != 0) {
		size++;
	}
    if (size == 0) {
        close(fd);
        return NULL;
    }
    close(fd);
	char *str = mx_strnew(size);
    if (str == NULL) {
        close(fd);
        return NULL;
    }
	int i = 0;
    fd = open(filename, O_RDONLY);
	while(read(fd, &ch, 1) != 0) {
		str[i] = ch;
		i++;
	}
	if (close(fd) == -1) {
        free(str);
        return NULL;
    }
	str[i] = '\0';
	return str;
}
