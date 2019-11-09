#ifndef CGRAPH_LIBRARY_H
#define CGRAPH_LIBRARY_H

typedef enum {
    UNDIRECTED, DIRECTED
} GraphDirection;

typedef enum {
    WEIGHTED, UNWEIGHTED
} GraphWeight;

typedef struct Graph {
    int **adjacent;
    GraphDirection direction;
    GraphWeight weight;
    unsigned int capacity;
} Graph;

/**
 * Initialize an empty graph.
 * @param weight If the graph is unweighted or weighted.
 * @param direction If the graph is undirected or directed.
 * @param capacity  The max vertices of the graph.
 * @return An empty initialized graph.
 */
Graph *init_graph(GraphWeight weight, GraphDirection direction, unsigned int capacity);

/**
 * Adds an unweighted edge to the graph.
 * @param graph The graph.
 * @param from The source edge.
 * @param to The destination edge.
 * @return  "0" if the edge can be added.
 *          "1" if "from" is out of bounds.
 *          "2" if "to" is out of bounds.
 */
int add_unweighted_edge(Graph *graph, unsigned int from, unsigned int to);

/**
 * Adds a weighted edge to the graph.
 * @param graph The graph.
 * @param from The source edge.
 * @param to The destination edge.
 * @return  "0" if the edge is added.
 *          "1" if "from" is out of bounds.
 *          "2" if "to" is out of bounds.
 */
int add_weighted_edge(Graph *graph, unsigned int from, unsigned int to, int weight);

/**
 * Removes an edge from the graph.
 * @param graph The graph.
 * @param from The source edge.
 * @param to The destination edge.
 * @return  "0" if edge is removed.
 *          "1" if "from" is out of bounds.
 *          "2" if "to" is out of bounds.
 */
int remove_edge(Graph *graph, unsigned int from, unsigned int to);

/**
 * Destroy and free the graph.
 * @param graph The graph.
 * @return 0 if graph got destroyed successfully.
 */
int destroy_graph(Graph *graph);

#endif //CGRAPH_LIBRARY_H