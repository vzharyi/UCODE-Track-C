#include "pathfinder.h"

void mx_print_line_error(int line) {
    char *line_number = mx_itoa(line);
    mx_printerr("error: line ");
    mx_printerr(line_number);
    mx_printerr(" is not valid\n");
    exit(1);
}

void validate_islands_number() {
    mx_printerr("error: invalid number of islands\n");
    exit(1);
}

void duplicate_bridges() {
    mx_printerr("error: duplicate bridges\n");
    exit(1);
}

void sum_of_bridges_lengths() {
    mx_printerr("error: sum of bridges lengths is too big\n");
    exit(1);
}
