#include "pathfinder.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    check_file_exist(argv[1]);
    int fd = open(argv[1], O_RDONLY);
    t_graph *graph = mx_input_handler(fd, argv[1]);
    mx_floyd_warshall(graph);
    mx_output_result(graph);
    mx_data_cleanup(graph);
    return 0;
}
