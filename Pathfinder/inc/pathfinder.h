#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

#define INT_MAX 2147483647

typedef struct {
    int num_nodes;
    int **adjacency_matrix;
    char **islands;
    int **distance_matrix;
    int **result_matrix;
}   t_graph;


void mx_floyd_warshall(t_graph *graph);
t_graph *mx_input_handler(int fd, char *file);
void mx_print_line_error(int line);
void check_file_exist(const char *file);
void handle_empty_file(const char *file);
void validate_length(const char *length, int line);
void validate_line(const char *island1, const char *island2, const char *length, int line);
void validate_islands_number(int currentIslandCount, int maxIslandCount, int last);
void duplicate_bridges(int currentWeight);
void sum_of_bridges_lengths(int *currentSum, int newLength);
void mx_data_cleanup(t_graph *graph);
void mx_output_result(t_graph *graph);

#endif
