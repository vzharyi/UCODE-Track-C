#include "pathfinder.h"

void mx_count_unique_islands(t_finder *path) {
    int counter = 0;

    path->unique_island = (char**)malloc(sizeof(char*) * path->number_of_words);

    for (int i = 1; i < path->number_of_words; i++) {
        if (mx_isdigit(path->islands[i][0])) {
            continue;
        }

        int is_unique = 1;
        for (int j = 0; j < counter; j++) {
            if (mx_strcmp(path->unique_island[j], path->islands[i]) == 0) {
                is_unique = 0;
                break;
            }
        }

        if (is_unique) {
            path->unique_island[counter] = mx_strdup(path->islands[i]);
            if (!path->unique_island[counter]) {
                return;
            }
            counter++;
        }
    }

    if (counter != path->number_of_islands) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
