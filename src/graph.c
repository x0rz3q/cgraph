#include "graph.h"
#include <stdlib.h>

Graph *init_graph(GraphWeight weight, GraphDirection direction, unsigned int capacity) {
    Graph *graph = malloc(sizeof(Graph));
    graph->direction = direction;
    graph->weight = weight;
    graph->adjacent = malloc(sizeof(int *) * capacity);
    graph->capacity = capacity;

    for (unsigned int i = 0; i < capacity; i++) {
        graph->adjacent[i] = malloc(sizeof(int) * capacity);
    }

    return graph;
}

int add_unweighted_edge(Graph *graph, unsigned int from, unsigned int to) {
    return add_weighted_edge(graph, from, to, 1);
}

int add_weighted_edge(Graph *graph, unsigned int from, unsigned int to, int weight) {
    if (from >= graph->capacity) return 1;
    if (to >= graph->capacity) return 2;

    graph->adjacent[from][to] = weight;

    if (graph->direction == UNDIRECTED) {
        graph->adjacent[to][from] = weight;
    }

    return 0;
}

int remove_edge(Graph *graph, unsigned int from, unsigned int to) {
    return add_weighted_edge(graph, from, to, 0);
}

int destroy_graph(Graph *graph) {
    for (unsigned int i = 0; i < graph->capacity; i++) {
        free(graph->adjacent[i]);
    }

    free(graph->adjacent);
    free(graph);

    return 0;
}