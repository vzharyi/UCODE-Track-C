#include "pathfinder.h"

t_path *mx_dijkstra(t_graph *graph, int index_begin) {
    t_path *nodes = (t_path *) malloc(sizeof(t_path) * graph->numIslands);
    int i = 0;
    while (i < graph->numIslands) {
        nodes[i].checked = false;
        nodes[i].initialPathLength = -1;
        nodes[i].islandPosition = i;
        nodes[i].prevNode = NULL;
        i++;
    }
    nodes[index_begin].initialPathLength = 0;

    for (int index_point = index_begin; index_point != -1;) {
        nodes[index_point].checked = true;
        int i = 0;
        while (i < graph->numIslands) {
            if (!nodes[i].checked && graph->connections[index_point][i] != -1) {
                int new_distance = nodes[index_point].initialPathLength + graph->connections[index_point][i];
                if (nodes[i].initialPathLength == -1 || new_distance <= nodes[i].initialPathLength) {
                    if (new_distance < nodes[i].initialPathLength)
                        mx_clear_list(&nodes[i].prevNode);
                    nodes[i].initialPathLength = new_distance;
                    mx_push_back(&nodes[i].prevNode, &nodes[index_point]);
                }
            }
            i++;
        }
        index_point = -1;
        i = 0;
        while (i < graph->numIslands) {
            if (!nodes[i].checked && nodes[i].initialPathLength != -1) {
                if (index_point == -1 || nodes[i].initialPathLength < nodes[index_point].initialPathLength) {
                    index_point = i;
                }
            }
            i++;
        }
    }

    return nodes;
}

t_list *generate_all_paths(t_path *node) {
    t_list *paths = NULL;
    if (node->initialPathLength == 0)
        return mx_create_node(mx_create_node(node));

    t_list *prevNode = node->prevNode;
    for (; prevNode != NULL; prevNode = prevNode->next) {
        t_list *tmp = generate_all_paths((t_path *) prevNode->data);
        for (t_list *current = tmp; current != NULL; current = current->next) {
            mx_push_back((t_list **) & current->data, node);
            mx_push_back(&paths, current->data);
        }
        mx_clear_list(&tmp);
    }
    return paths;
}
