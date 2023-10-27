#include "pathfinder.h"

void mx_handle_empty_file_error(char *argv[], t_finder *path) {
    // Пустий файл
    char buff;
    int fd = open(argv[1], O_RDONLY);
    if (read(fd, &buff, 1) < 1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        free(path);
        close(fd);
        exit(1);
    }

    path->string = mx_file_to_str(argv[1]);
}
