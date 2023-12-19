#include "pathfinder.h"

static bool process_line(t_graph *graph, int fd, char **island1, char **island2, int *length_connections) {
    int value_size = mx_read_line(island1, 1, '-', fd);
    if (value_size < 0)
        return false;

    value_size = mx_read_line(island2, 1, ',', fd);
    if (value_size < 0) {
        mx_strdel(island1);
        graph->clears = true;
        return false;
    }
    char *length_connections_string = NULL;
    value_size = mx_read_line(&length_connections_string, 1, '\n', fd);
    if (value_size < 0) {
        mx_strdel(island1);
        mx_strdel(island2);
        graph->clears = true;
        return false;
    }

    int length_positive = 0;
    if (length_connections_string[0] == '+')
        length_positive = 1;
    for (int i = length_positive; length_connections_string[i] != '\0'; i++)
        if (!mx_isdigit(length_connections_string[i])) {
            mx_strdel(island1);
            mx_strdel(island2);
            mx_strdel(&length_connections_string);
            graph->clears = true;
            return false;
        }

    *length_connections = mx_atoi(length_connections_string);
    mx_strdel(&length_connections_string);

    int size_island1 = mx_strlen(*island1);
    if (size_island1 == 0) {
        mx_strdel(island1);
        mx_strdel(island2);
        graph->clears = true;
        return false;
    }
    for (int i = 0; i < size_island1; i++) {
        if (!mx_isalpha((*island1)[i])) {
            mx_strdel(island1);
            mx_strdel(island2);
            graph->clears = true;
            return false;
        }
    }

    int size_island2 = mx_strlen(*island2);
    if (size_island2 == 0) {
        mx_strdel(island1);
        mx_strdel(island2);
        graph->clears = true;
        return false;
    }
    for (int i = 0; i < size_island2; i++) {
        if (!mx_isalpha((*island2)[i])) {
            mx_strdel(island1);
            mx_strdel(island2);
            graph->clears = true;
            return false;
        }
    }

    if (mx_strcmp(*island1, *island2) == 0 || *length_connections <= 0) {
        mx_strdel(island1);
        mx_strdel(island2);
        graph->clears = true;
        return false;
    }
    return true;
}

t_graph *mx_input_handler(int fd, const char *file) {
    t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
    graph->clears = false;
    graph->reachedMaxLimit = false;
    graph->hasDuplicateConnections = false;
    graph->numIslands = 0;
    graph->islands = NULL;
    graph->connections = NULL;

    int line_count = 1;
    bool mustContinue = true;
    char *length = NULL;
    int value_size = mx_read_line(&length, 1, '\n', fd);
    if (value_size < 0) {
        mx_print_line_error(line_count);
        exit(1);
    }
    int length_positive = 0;
    if (length[0] == '+')
        length_positive = 1;
    for (int i = length_positive; length[i] != '\0'; i++)
        if (!mx_isdigit(length[i])) {
            mx_strdel(&length);
            mx_print_line_error(line_count);
            exit(1);
        }
    int islands_total = mx_atoi(length);
    if (islands_total <= 0) {
        mx_strdel(&length);
        mx_print_line_error(line_count);
        exit(1);
    }
    mx_strdel(&length);

    graph->islands = (char **)malloc(sizeof(char *) * islands_total);
    graph->connections = (int **)malloc(sizeof(int *) * islands_total);
    for (int i = 0; i < islands_total; i++) {
        graph->islands[i] = NULL;
        graph->connections[i] = (int *)malloc(sizeof(int) * islands_total);
        for (int j = 0; j < islands_total; j++)
            graph->connections[i][j] = -1;
    }

    while (true) {
        line_count++;
        char *island1 = NULL;
        char *island2 = NULL;
        int length_connections = 0;

        mustContinue = process_line(graph, fd, &island1, &island2, &length_connections);
        if (graph->clears)
            mx_print_line_error(line_count);
        if (!mustContinue) {
            char *string_file = mx_file_to_str(file);
            mx_str_reverse(string_file);
            if (string_file[0] != '\n') {
                line_count--;
                graph->clears = true;
                mx_print_line_error(line_count);
            }
            mx_strdel(&string_file);

            break;
        }

        int locationsIsland[2] = {-1, -1};
        for (int i = 0; i < graph->numIslands; i++) {
            if (mx_strcmp(island1, graph->islands[i]) == 0) {
                locationsIsland[0] = i;
                break;
            }
        }
        for (int i = 0; i < graph->numIslands; i++) {
            if (mx_strcmp(island2, graph->islands[i]) == 0) {
                locationsIsland[1] = i;
                break;
            }
        }

        char *locationsIslands[2] = {island1, island2};
        for (int i = 0; i < 2; i++)
            if (locationsIsland[i] == -1 && !graph->reachedMaxLimit) {
                graph->islands[graph->numIslands] = mx_strdup(locationsIslands[i]);
                graph->connections[graph->numIslands][graph->numIslands] = 0;
                locationsIsland[i] = graph->numIslands;
                graph->numIslands++;
                if (graph->numIslands == islands_total)
                    graph->reachedMaxLimit = true;
            }
        for (int i = 0; i < 2; i++) {
            if (locationsIsland[i] == -1) {
                validate_islands_number();
                graph->clears = true;
                break;
            }
        }

        if (graph->connections[locationsIsland[0]][locationsIsland[1]] != -1)
            graph->hasDuplicateConnections = true;
        else {
            graph->connections[locationsIsland[0]][locationsIsland[1]] = length_connections;
            graph->connections[locationsIsland[1]][locationsIsland[0]] = length_connections;
        }

        if (graph->clears || graph->hasDuplicateConnections)
            break;
        mx_strdel(&island1);
        mx_strdel(&island2);
    }

    if (!graph->clears) {
        graph->clears = true;
        if (!graph->reachedMaxLimit) {
            validate_islands_number();
        } else if (graph->hasDuplicateConnections) {
            duplicate_bridges();
        } else {
            unsigned int sum = 0;
            for (int i = 0; i < graph->numIslands; i++)
                for (int j = 0; j < i; j++)
                    if (graph->connections[i][j] != -1) {
                        sum += graph->connections[i][j];
                    }
            if (sum > INT_MAX) {
                sum_of_bridges_lengths();
            } else {
                graph->clears = false;
            }
        }
    }
    if (graph->clears) {
        clear_graph(graph, islands_total);
        exit(1);
    }
    return graph;
}
