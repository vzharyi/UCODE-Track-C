#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

#define INT_MAX 2147483647

typedef struct {
    int number_of_islands;
    int number_of_words;
    int **result_arr;
    int **initial_arr;
    char *string;
    char **islands;
    char **unique_island;
}   t_finder;

typedef struct {
    int distance;
    int *route;
}   t_output;

int main(int argc, char *argv[]);
void mx_error_handling(int argc, char *argv[], t_finder *path);

void mx_handle_arg_count_error(int argc);
void mx_check_file_exist_error(char *argv[], t_finder *path);
void mx_handle_empty_file_error(char *argv[], t_finder *path);
void mx_print_line_error(int line);
void mx_handle_first_line_error(t_finder *path);
void mx_input_line_validation(t_finder *path);
void mx_count_unique_islands(t_finder *path);
void mx_duplicate_bridges_error(t_finder *path);
void mx_sum_of_bridges_lengths_error(t_finder *path);
void mx_input_islands_validation(t_finder *path);
void mx_create_matrix(t_finder *path);
void mx_print_result(t_finder *path);
void mx_floyd_warshall(t_finder *path);
void mx_clean_memory(t_finder *path);

#endif
