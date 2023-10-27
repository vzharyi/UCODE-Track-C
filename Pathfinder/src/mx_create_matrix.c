#include "pathfinder.h"

static int get_number_of_islands(t_finder *path, char *island) {
    for (int i = 0; i < path->number_of_islands; i++)
        if (mx_strcmp(island, path->unique_island[i]) == 0)
            return i;

    return 0;
}

static void initialize_matrix(t_finder *path) {
    path->initial_arr = (int **) malloc(sizeof(int *) * path->number_of_islands);
    path->result_arr = (int **) malloc(sizeof(int *) * path->number_of_islands);

    for (int i = 0; i < path->number_of_islands; i++) {
        path->initial_arr[i] = (int *) malloc(sizeof(int) * path->number_of_islands);
        path->result_arr[i] = (int *) malloc(sizeof(int) * path->number_of_islands);

        for (int j = 0; j < path->number_of_islands; j++) {
            if (i == j)
                path->result_arr[i][j] = 0;
            else
                path->result_arr[i][j] = INT_MAX;
        }
    }
}

static void fill_matrix(t_finder *path) {
    for (int index = 1; index < path->number_of_words; index += 3) {
        int i = get_number_of_islands(path, path->islands[index]);
        int j = get_number_of_islands(path, path->islands[index + 1]);
        int bridge_length = mx_atoi(path->islands[index + 2]);

        path->result_arr[i][j] = bridge_length;
        path->result_arr[j][i] = bridge_length;
    }
}

void mx_create_matrix(t_finder *path) {
    initialize_matrix(path);
    fill_matrix(path);
    mx_del_strarr(&path->islands);
}
