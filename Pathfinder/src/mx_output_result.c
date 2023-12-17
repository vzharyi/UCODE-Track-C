#include "pathfinder.h"

static void print_route(t_graph *graph, int i, int j) {
    if (graph->result_matrix[i][j] == i)
        return;
    print_route(graph, i, graph->result_matrix[i][j]);
    mx_printstr(graph->islands[graph->result_matrix[i][j]]);
    mx_printstr(" -> ");
}

void mx_output_result(t_graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = i; j < graph->num_nodes; j++) {
            if (j != i && graph->result_matrix[i][j] != -1) {
                mx_printstr("========================================\n");
                mx_printstr("Path: ");
                char *name_i = graph->islands[i];
                char *name_j = graph->islands[j];
                mx_printstr(name_i);
                mx_printstr(" -> ");
                mx_printstr(name_j);
                mx_printchar('\n');
                mx_printstr("Route: ");
                mx_printstr(name_i);
                mx_printstr(" -> ");
                print_route(graph, i, j);
                mx_printstr(name_j);
                mx_printchar('\n');
                mx_printstr("Distance: ");
                if (graph->adjacency_matrix[i][j] == graph->distance_matrix[i][j])
                    mx_printint(graph->adjacency_matrix[i][j]);
                else {
                    int path[graph->num_nodes];
                    int count = 0;
                    int temp_j = j;
                    while (graph->result_matrix[i][temp_j] != i) {
                        path[count++] = temp_j;
                        temp_j = graph->result_matrix[i][temp_j];
                    }
                    path[count++] = temp_j;
                    for (int k = count - 1; k >= 0; k--) {
                        mx_printint(graph->adjacency_matrix[graph->result_matrix[i][path[k]]][path[k]]);
                        if (k > 0) {
                            mx_printstr(" + ");
                        }
                    }
                    mx_printstr(" = ");
                    mx_printint(graph->adjacency_matrix[i][j]);
                }
                mx_printchar('\n');
                mx_printstr("========================================\n");
            }
        }
    }
}
