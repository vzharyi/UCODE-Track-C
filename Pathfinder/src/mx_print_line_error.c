#include "pathfinder.h"

void mx_print_line_error(int line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line));
    mx_printerr(" is not valid\n");
    exit(1);
}
