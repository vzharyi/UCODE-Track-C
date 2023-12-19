#include "pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    char buff;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    int n_read = read(fd, &buff, 1);
    close(fd);
    if (n_read == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    int fd_main = open(argv[1], O_RDONLY);
    t_graph *graph = mx_input_handler(fd_main, argv[1]);
    for (int i = 0; i < graph->numIslands; i++) {
        t_path *nodes = mx_dijkstra(graph, i);
        mx_output_result(graph, nodes, i);
        clear_nodes(nodes, graph->numIslands);
    }
    clear_graph(graph, graph->numIslands);
    return 0;
}
