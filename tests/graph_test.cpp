#include <gtest/gtest.h>
#include <graph.h>

/**
 * Tests the initialization of the graph.
 */
TEST(GraphTest, InitializeGraph) {
    Graph *graph = init_graph(UNWEIGHTED, UNDIRECTED, 2);

    EXPECT_EQ(graph->capacity, 2);
    EXPECT_EQ(graph->direction, UNDIRECTED);
    EXPECT_EQ(graph->weight, UNWEIGHTED);
}

/**
 * Tests the addition of an unweighted undirected edge.
 */
TEST(GraphTest, AddUnweightedEdgeToUndirectedGraph) {
    Graph *graph = init_graph(UNWEIGHTED, UNDIRECTED, 2);
    EXPECT_EQ(add_unweighted_edge(graph, 0, 1), GRAPH_SUCCESS);

    EXPECT_EQ(graph->adjacent[0][1], 1);
    EXPECT_EQ(graph->adjacent[1][0], 1);
}

/**
 * Tests the addition of an weighted undirected edge.
 */
TEST(GraphTest, AddWeightedEdgeToUndirectedGraph) {
    Graph *graph = init_graph(WEIGHTED, UNDIRECTED, 2);
    EXPECT_EQ(add_weighted_edge(graph, 0, 1, 2), GRAPH_SUCCESS);

    EXPECT_EQ(graph->adjacent[0][1], 2);
    EXPECT_EQ(graph->adjacent[1][0], 2);
}

/**
 * Tests the addition of an unweighted directed edge.
 */
TEST(GraphTest, AddUnweightedEdgeDirectedGraph) {
    Graph *graph = init_graph(UNWEIGHTED, DIRECTED, 2);
    add_unweighted_edge(graph, 0, 1);

    EXPECT_EQ(graph->adjacent[0][1], 1);
    EXPECT_EQ(graph->adjacent[1][0], 0);
}

/**
 * Tests the addition of an weighted directed edge.
 */
TEST(GraphTest, AddWeightedEdgeToDirectedGraph) {
    Graph *graph = init_graph(WEIGHTED, DIRECTED, 2);
    add_weighted_edge(graph, 0, 1, 2);

    EXPECT_EQ(graph->adjacent[0][1], 2);
    EXPECT_EQ(graph->adjacent[1][0], 0);
}

/**
 * Tests the removal of an edge.
 */
TEST(GraphTest, RemoveEdgeFromUndirectedGraph) {
    Graph *graph = init_graph(UNWEIGHTED, UNDIRECTED, 4);
    add_unweighted_edge(graph, 0, 1);
    add_unweighted_edge(graph, 3, 0);

    EXPECT_EQ(remove_edge(graph, 0, 1), GRAPH_SUCCESS);
    EXPECT_EQ(graph->adjacent[0][1], 0);
    EXPECT_EQ(graph->adjacent[1][0], 0);
    EXPECT_EQ(graph->adjacent[3][0], 1);
    EXPECT_EQ(graph->adjacent[0][3], 1);
}

/**
 * Tests the destruction of a graph.
 */
TEST(GraphTest, DestroyGraph) {
    Graph *graph = init_graph(UNWEIGHTED, UNDIRECTED, 50);

    EXPECT_EQ(destroy_graph(graph), GRAPH_SUCCESS);
}

/**
 * Tests "from" out of bounds return code.
 */
TEST(GraphTest, FromOutOfBound) {
    Graph *graph = init_graph(UNWEIGHTED, UNDIRECTED, 4);
    EXPECT_EQ(add_unweighted_edge(graph, 4, 0), GRAPH_ERR_FROM_OUT_OF_BOUNDS);
}

/**
 * Tests "to" out of bounds return code.
 */
TEST(GraphTest, ToOutOfBound) {
    Graph *graph = init_graph(UNWEIGHTED, UNDIRECTED, 4);

    EXPECT_EQ(add_unweighted_edge(graph, 0, 4), GRAPH_ERR_TO_OUT_OF_BOUNDS);
}