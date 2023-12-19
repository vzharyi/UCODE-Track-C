#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct {
    char** islands;
    int** connections;
    int numIslands;
    bool clears;
    bool reachedMaxLimit;
    bool hasDuplicateConnections;
}   t_graph;

typedef struct {
    bool checked;
    int initialPathLength;
    int islandPosition;
    t_list *prevNode;
}   t_path;

t_path *mx_dijkstra(t_graph *graph, int index_begin);
t_list *generate_all_paths(t_path *node);
t_graph *mx_input_handler(int fd, const char *file);
void mx_output_result(t_graph *graph, t_path *nodes, int idx_first);
void clear_graph(t_graph *graph, int islands_total);
void clear_nodes(t_path *nodes, int numIslands);
void mx_print_line_error(int line);
void validate_islands_number();
void duplicate_bridges();
void sum_of_bridges_lengths();

#endif
