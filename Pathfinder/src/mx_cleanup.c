#include "pathfinder.h"

void clear_graph(t_graph *graph, int islands_total) {
    int i = 0;
    while (i < islands_total) {
        mx_strdel(&graph->islands[i]);
        free(graph->connections[i]);
        i++;
    }
    free(graph->islands);
    free(graph->connections);
    free(graph);
}

void clear_nodes(t_path *nodes, int numIslands) {
    for (int i = 0; i < numIslands; i++)
        mx_clear_list(&nodes[i].prevNode);
    free(nodes);
}
