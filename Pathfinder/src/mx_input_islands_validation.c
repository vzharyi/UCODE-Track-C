#include "pathfinder.h"

void mx_input_islands_validation(t_finder *path) {
    char *buff = mx_strdup(path->string);

    path->number_of_islands = mx_atoi(buff);

    for (int i = 0; buff[i] != '\0'; i++) {
        if(buff[i] == ',' || buff[i] == '\n')
            buff[i] = '-';
    }

    path->number_of_words = mx_count_words(buff, '-');
    path->islands = mx_strsplit(buff, '-');
    mx_count_unique_islands(path);
    mx_duplicate_bridges_error(path);
    mx_sum_of_bridges_lengths_error(path);

    free(buff);
    free(path->string);
}
