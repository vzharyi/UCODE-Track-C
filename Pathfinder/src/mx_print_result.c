#include "pathfinder.h"

static void shortest_route(t_finder *path, t_output *solution) {
    int i = solution->route[solution->distance];
    int j = solution->route[0];

    for (int k = 0; k < path->number_of_islands; k++) {
        if (k != solution->route[solution->distance] &&
            (path->initial_arr[i][k] == path->result_arr[i][j] - path->result_arr[k][j])) {
            solution->distance++;
            solution->route[solution->distance] = k;
            shortest_route(path, solution);
            solution->distance--;
        }
    }

    if (solution->route[solution->distance] != solution->route[0])
        return;

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path->unique_island[solution->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(path->unique_island[solution->route[0]]);
    mx_printstr("\n");

    mx_printstr("Route: ");
    for (int i = 1; i < solution->distance + 1;) {
        mx_printstr(path->unique_island[solution->route[i]]);

        if (++i < solution->distance + 1)
            mx_printstr(" -> ");
    }
    mx_printstr("\n");

    int sum = 0;
    mx_printstr("Distance: ");
    for (int i = 1; i < solution->distance; i++) {
        mx_printint(path->initial_arr[solution->route[i]][solution->route[i + 1]]);
        sum += path->initial_arr[solution->route[i]][solution->route[i + 1]];

        if (i < solution->distance - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_printstr("========================================\n");
}

void mx_print_result(t_finder *path) {
    for (int i = 0; i < path->number_of_islands; i++) {
        for (int j = i + 1; j < path->number_of_islands; j++) {
            t_output *solution = (t_output*)malloc(sizeof(t_output));
            solution->route = (int*)malloc(sizeof(int) * (path->number_of_islands + 1));
            solution->distance = 1;
            solution->route[0] = j;
            solution->route[1] = i;
            shortest_route(path, solution);

            free(solution->route);
            free(solution);
        }
    }
    mx_clean_memory(path);
}
