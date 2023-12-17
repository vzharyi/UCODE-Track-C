#include "pathfinder.h"

static void free_array(int **array, int size) {
    for(int i = 0; i < size; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
}

void mx_data_cleanup(t_graph *graph) {
    mx_del_strarr(&(graph->islands));
    graph->islands = NULL;
    free_array(graph->distance_matrix, graph->num_nodes);
    free_array(graph->result_matrix, graph->num_nodes);
    free_array(graph->adjacency_matrix, graph->num_nodes);
    free(graph);
    graph = NULL;
}
