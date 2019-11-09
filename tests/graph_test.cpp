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
    add_unweighted_edge(graph, 0, 1);
    EXPECT_EQ(graph->adjacent[0][1], 1);
    EXPECT_EQ(graph->adjacent[1][0], 1);
}