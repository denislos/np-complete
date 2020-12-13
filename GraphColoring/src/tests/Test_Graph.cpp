#include <gtest/gtest.h>

#include <graph.h>

namespace UT
{

TEST(TestGraph, EmptyGraphUnit)
{
    Graph g;
    
    EXPECT_EQ(g.get_num_vertices(), 0u);
}

TEST(TestGraph, AddSameEdgeUnit)
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(1, 0);
    
    EXPECT_EQ(g.get_num_vertices(), 2u);
    EXPECT_TRUE(g.has_edge(0, 1));
    EXPECT_TRUE(g.has_edge(1, 0));
}

TEST(TestGraph, AddEdgesUnit)
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(3, 4);
    
    EXPECT_EQ(g.get_num_vertices(), 5u);
    EXPECT_TRUE(g.has_edge(0, 1));
    EXPECT_TRUE(g.has_edge(0, 2));
    EXPECT_TRUE(g.has_edge(0, 3));
    EXPECT_TRUE(g.has_edge(1, 2));
    EXPECT_TRUE(g.has_edge(3, 4));
    EXPECT_FALSE(g.has_edge(0, 4));
}

TEST(TestGraph, BruteForceColoringTwoColorUnit)
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);

    std::size_t colors = g.brute_force_chromatic_number();
}

}