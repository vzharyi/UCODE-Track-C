#include "pathfinder.h"

t_graph *mx_input_handler(int fd, char *file) {
    char *line = mx_strnew(20);
    if (!mx_read_line(&line, 5, '\n', fd))
        handle_empty_file(file);
    validate_length(line, 1);
    int result = mx_atoi(line);
    mx_strdel(&line);

    t_graph *graph = malloc(sizeof(t_graph));
    graph->num_nodes = result;

    graph->distance_matrix = malloc(graph->num_nodes * sizeof(int*));
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->distance_matrix[i] = malloc(graph->num_nodes * sizeof(int));
        for (int j = 0; j < graph->num_nodes; j++) {
            if (i == j)
                graph->distance_matrix[i][j] = 0;
            else
                graph->distance_matrix[i][j] = INT_MAX;
        }
    }

    graph->adjacency_matrix = malloc(graph->num_nodes * sizeof(int*));
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->adjacency_matrix[i] = malloc(graph->num_nodes * sizeof(int));
        for (int j = 0; j < graph->num_nodes; j++) {
            if (i == j)
                graph->adjacency_matrix[i][j] = 0;
            else
                graph->adjacency_matrix[i][j] = INT_MAX;
        }
    }

    graph->result_matrix = malloc(graph->num_nodes * sizeof(int*));
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->result_matrix[i] = malloc(graph->num_nodes * sizeof(int));
        for (int j = 0; j < graph->num_nodes; j++) {
            if (i == j)
                graph->result_matrix[i][j] = 0;
            else
                graph->result_matrix[i][j] = INT_MAX;
        }
    }

    graph->islands = malloc((graph->num_nodes + 1) * sizeof(char*));
    for (int i = 0; i <= graph->num_nodes; i++)
        graph->islands[i] = NULL;

    char *input_str = mx_strnew(100);
    int index = 0, total_bridge_length = 0, strings = 1;
    while (mx_read_line(&input_str, 5, '\n', fd) > 0) {
        strings++;
        char **tokens_line = mx_strsplit(input_str, ',');
        char **tokens_islands = mx_strsplit(tokens_line[0], '-');
        validate_line(tokens_islands[0], tokens_islands[1], tokens_line[1], strings);

        bool contains_string1 = false;
        for (int i = 0; graph->islands[i] != NULL; i++) {
            if (!mx_strcmp(tokens_islands[0], graph->islands[i])) {
                contains_string1 = true;
                break;
            }
        }
        if (!contains_string1) {
            validate_islands_number(index, graph->num_nodes, 0);
            graph->islands[index] = mx_strdup(tokens_islands[0]);
            index += 1;
        }

        bool contains_string2 = false;
        for (int i = 0; graph->islands[i] != NULL; i++) {
            if (!mx_strcmp(tokens_islands[1], graph->islands[i])) {
                contains_string2 = true;
                break;
            }
        }
        if (!contains_string2) {
            validate_islands_number(index, graph->num_nodes, 0);
            graph->islands[index] = mx_strdup(tokens_islands[1]);
            index += 1;
        }

        int a = -1;
        for (int i = 0; graph->islands[i] != NULL; i++) {
            if (!mx_strcmp(graph->islands[i], tokens_islands[0])) {
                a = i;
                break;
            }
        }

        int b = -1;
        for (int i = 0; graph->islands[i] != NULL; i++) {
            if (!mx_strcmp(graph->islands[i], tokens_islands[1])) {
                b = i;
                break;
            }
        }

        int current_weight = mx_atoi(tokens_line[1]);
        duplicate_bridges(graph->distance_matrix[a][b]);
        sum_of_bridges_lengths(&total_bridge_length, current_weight);

        graph->distance_matrix[a][b] = current_weight;
        graph->distance_matrix[b][a] = current_weight;

        mx_del_strarr(&tokens_line);
        mx_del_strarr(&tokens_islands);
    }

    mx_strdel(&input_str);
    validate_islands_number(index, graph->num_nodes, 1);

    close(fd);
    return graph;
}
