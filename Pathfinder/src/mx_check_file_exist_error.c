#include "pathfinder.h"

void mx_check_file_exist_error(char *argv[], t_finder *path) {
    // Файл не існує
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        free(path);
        exit(1);
    }
    close(fd);
}
