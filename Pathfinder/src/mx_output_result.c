#include <pathfinder.h>

static void output(t_graph *graph, t_list *path, int idx_first, int idx_final) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(graph->islands[idx_first]);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[idx_final]);
    mx_printchar('\n');
    mx_printstr("Route: ");

    t_list *now = path;
    while (now != NULL) {
        t_path *node = (t_path *)now->data;
        if (node->initialPathLength != 0)
            mx_printstr(" -> ");
        mx_printstr(graph->islands[node->islandPosition]);
        now = now->next;
    }

    mx_printchar('\n');
    mx_printstr("Distance: ");

    for (; path != NULL && path->next != NULL; path = path->next) {
        t_path *node = (t_path *) path->data;
        t_path *next_node = (t_path *) path->next->data;
        if (node->initialPathLength != 0)
            mx_printstr(" + ");
        mx_printint(next_node->initialPathLength - node->initialPathLength);
        if (node->initialPathLength != 0 && path->next->next == NULL) {
            mx_printstr(" = ");
            mx_printint(next_node->initialPathLength);
        }
    }
    mx_printchar('\n');
    mx_printstr("========================================\n");
}

static bool function_compare(void *one_path, void *second_path) {
    one_path = ((t_list*)one_path)->next;
    second_path = ((t_list*)second_path)->next;
    while((t_list*)one_path != NULL && (t_list*)second_path != NULL ) {
        t_path *one_node = (t_path *)(((t_list*)one_path)->data);
        t_path *second_node = (t_path *)(((t_list*)second_path)->data);
        if(one_node->islandPosition > second_node->islandPosition)
            return true;
        one_path = ((t_list*)one_path)->next;
        second_path = ((t_list*)second_path)->next;
        if(one_node->islandPosition != second_node->islandPosition)
            return false;
    }
    return false;
}

void mx_output_result(t_graph *graph, t_path *nodes, int idx_first) {
    int idx_final = idx_first + 1;
    while (idx_final < graph->numIslands) {
        t_list *paths_to_ending = generate_all_paths(&nodes[idx_final]);
        mx_sort_list(paths_to_ending, function_compare);
        t_list *now_path = paths_to_ending;
        for (; now_path != NULL; now_path = now_path->next) {
            t_list *path = (t_list *) now_path->data;
            output(graph, path, idx_first, idx_final);
            mx_clear_list(&path);
        }
        mx_clear_list(&paths_to_ending);
        idx_final++;
    }
}
