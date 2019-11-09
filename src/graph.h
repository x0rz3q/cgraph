#ifndef CGRAPH_LIBRARY_GRAPH_H
#define CGRAPH_LIBRARY_GRAPH_H

/* function return codes. */
#define GRAPH_ERR_FROM_OUT_OF_BOUNDS 1
#define GRAPH_ERR_TO_OUT_OF_BOUNDS 2
#define GRAPH_SUCCESS 0

#ifdef __cplusplus
extern "C" {
#endif

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
 * @return  GRAPH_SUCCESS if the edge can be added.
 *          GRAPH_ERR_FROM_OUT_OF_BOUNDS if "from" is out of bounds.
 *          GRAPH_ERR_TO_OUT_OF_BOUNDS if "to" is out of bounds.
 */
int add_unweighted_edge(Graph *graph, unsigned int from, unsigned int to);

/**
 * Adds a weighted edge to the graph.
 * @param graph The graph.
 * @param from The source edge.
 * @param to The destination edge.
 * @return  GRAPH_SUCCESS if the edge is added.
 *          GRAPH_ERR_FROM_OUT_OF_BOUNDS if "from" is out of bounds.
 *          GRAPH_ERR_TO_OUT_OF_BOUNDS if "to" is out of bounds.
 */
int add_weighted_edge(Graph *graph, unsigned int from, unsigned int to, int weight);

/**
 * Removes an edge from the graph.
 * @param graph The graph.
 * @param from The source edge.
 * @param to The destination edge.
 * @return  GRAPH_SUCCESS if edge is removed.
 *          GRAPH_ERR_FROM_OUT_OF_BOUNDS if "from" is out of bounds.
 *          GRAPH_ERR_TO_OUT_OF_BOUNDS if "to" is out of bounds.
 */
int remove_edge(Graph *graph, unsigned int from, unsigned int to);

/**
 * Destroy and free the graph.
 * @param graph The graph.
 * @return GRAPH_SUCCESS if graph got destroyed successfully.
 */
int destroy_graph(Graph *graph);

#ifdef __cplusplus
}
#endif

#endif //CGRAPH_LIBRARY_GRAPH_H