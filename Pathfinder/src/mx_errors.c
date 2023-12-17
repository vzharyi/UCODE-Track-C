#include "pathfinder.h"

void check_file_exist(const char *file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    close(fd);
}

void handle_empty_file(const char *file) {
    mx_printerr("error: file ");
    mx_printerr(file);
    mx_printerr(" is empty\n");
    exit(1);
}

void validate_length(const char *length, int line) {
    for (int i = 0; length[i] != '\0'; i++)
        if(!mx_isdigit(length[i]))
            mx_print_line_error(line);
    if(mx_atoi(length) <= 0)
        mx_print_line_error(line);
}

static void validate_alpha(const char *str, int line) {
    for (int i = 0; str[i] != '\0'; i++)
        if(!mx_isalpha(str[i]))
            mx_print_line_error(line);
}

void validate_line(const char *island1, const char *island2, const char *length, int line) {
    if (!island1 || !island2 || !length)
        mx_print_line_error(line);
    validate_alpha(island1, line);
    validate_alpha(island2, line);
    if (!mx_strcmp(island1, island2))
        mx_print_line_error(line);
    validate_length(length, line);
}

void validate_islands_number(int currentIslandCount, int maxIslandCount, int last) {
    if ((!last && currentIslandCount >= maxIslandCount) || (last && currentIslandCount != maxIslandCount)) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}

void duplicate_bridges(int currentWeight) {
    if (currentWeight < INT_MAX) {
        mx_printerr("error: duplicate bridges\n");
        exit(1);
    }
}

void sum_of_bridges_lengths(int *currentSum, int newLength) {
    if (newLength > INT_MAX - *currentSum) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
    *currentSum += newLength;
}
