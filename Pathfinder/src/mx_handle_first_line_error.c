#include "pathfinder.h"

void mx_handle_first_line_error(t_finder *path) {
    while (*path->string != '\n') {
        if (!mx_isdigit(*path->string)) {
            mx_print_line_error(1);
        }
        path->string++;
    }
    path->string++;
}
