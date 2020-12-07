#pragma once


#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

class Graph
{
public:
    explicit Graph(std::size_t num_vertices)
        : num_vertices(num_vertices)
    { }

    void add_edge(std::size_t va, std::size_t vb);

    std::vector<std::size_t> brute_force_optimal_color() const;
    std::vector<std::size_t> small_mis_optimal_color() const;

private:
    std::size_t num_vertices = 0;

    struct coord_t {
        using kind = boost::vertex_property_tag;
    };

    using VertexProperty = boost::property<coord_t, std::size_t>; 
    
    using InternalGraph = boost::adjacency_list<boost::listS,
                                                boost::vecS,
                                                boost::undirectedS,
                                                VertexProperty>;
    
    using edge_t   = boost::graph_traits<InternalGraph>::edge_descriptor;  
    using vertex_t = boost::graph_traits<InternalGraph>::vertex_descriptor;

    InternalGraph adjacency_list;
};