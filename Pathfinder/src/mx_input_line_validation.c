#include "pathfinder.h"

static void checkHyphen(t_finder *path, int line) {
    if (*path->string == '-' && !mx_isalpha(*(path->string - 1))
        && !mx_isalpha(*(path->string + 1)))
        mx_print_line_error(line);
    path->string++;
}

static void checkComma(t_finder *path, int line) {
    while (*path->string != ',') {
        if (!mx_isalpha(*path->string))
            mx_print_line_error(line);
        path->string++;
    }
    if (*path->string == ',' && !mx_isalpha(*(path->string - 1))
        && !mx_isdigit(*(path->string + 1)))
        mx_print_line_error(line);
    path->string++;
}

void mx_input_line_validation(t_finder *path) {
    int line = 1;
    for (; *path->string != '\0'; path->string++) {
        while (*path->string != '-') {
            if (!mx_isalpha(*path->string))
                mx_print_line_error(line);

            path->string++;
        }
        line++;
        checkHyphen(path, line);
        checkComma(path, line);

        while (*path->string != '\n') {
            if (!mx_isdigit(*path->string) || mx_atoi(path->string) > INT_MAX)
                mx_print_line_error(line);

            path->string++;
        }
    }
}
