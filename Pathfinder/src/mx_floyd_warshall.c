#include "pathfinder.h"

void mx_floyd_warshall(t_graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            graph->adjacency_matrix[i][j] = (i == j) ? 0 : graph->distance_matrix[i][j];
            graph->result_matrix[i][j] = (i == j || graph->adjacency_matrix[i][j] == INT_MAX) ? INT_MAX : i;
        }
    }

    for (int k = 0; k < graph->num_nodes; k++) {
        for (int i = 0; i < graph->num_nodes; i++) {
            for (int j = 0; j < graph->num_nodes; j++) {
                if (graph->adjacency_matrix[i][k] != INT_MAX
                    && graph->adjacency_matrix[k][j] != INT_MAX
                    && graph->adjacency_matrix[i][k] + graph->adjacency_matrix[k][j] < graph->adjacency_matrix[i][j]) {
                    graph->adjacency_matrix[i][j] = graph->adjacency_matrix[i][k] + graph->adjacency_matrix[k][j];
                    graph->result_matrix[i][j] = graph->result_matrix[k][j];
                }
            }
        }
    }
}
