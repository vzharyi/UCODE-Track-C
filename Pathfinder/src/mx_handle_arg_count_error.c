#include "pathfinder.h"

void mx_handle_arg_count_error(int argc) {
    // Невірна кількість аргументів командного рядка
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
