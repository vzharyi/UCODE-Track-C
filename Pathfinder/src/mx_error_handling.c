#include "pathfinder.h"

void mx_error_handling(int argc, char *argv[], t_finder *path) {
    char *buff;
    mx_handle_arg_count_error(argc);
    mx_check_file_exist_error(argv, path);
    mx_handle_empty_file_error(argv, path);
    buff = path->string;
    mx_handle_first_line_error(path);
    mx_input_line_validation(path);
    path->string = buff;
    mx_input_islands_validation(path);
}
