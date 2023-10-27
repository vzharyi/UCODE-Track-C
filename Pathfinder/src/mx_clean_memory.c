#include "pathfinder.h"

void mx_clean_memory(t_finder *path) {
    if (path) {
        mx_del_strarr(&path->unique_island);

        if (path->result_arr) {
            for (int i = 0; i < path->number_of_islands; i++)
                free(path->result_arr[i]);
            free(path->result_arr);
        }

        if (path->initial_arr) {
            for (int i = 0; i < path->number_of_islands; i++)
                free(path->initial_arr[i]);
            free(path->initial_arr);
        }
        free(path);
    }
}
