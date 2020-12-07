
#include "graph.h"
#include "perm_repeat_generator.h"

#include <tuple>
#include <iostream>

void Graph::add_edge(std::size_t va, std::size_t vb)
{
    auto vertex_va = boost::add_vertex(va, adjacency_list);
    auto vertex_vb = boost::add_vertex(vb, adjacency_list);

    boost::add_edge(vertex_va, vertex_vb, adjacency_list);
}

std::vector<std::size_t> Graph::brute_force_optimal_color() const
{
    const std::size_t num_vertices = boost::num_vertices(adjacency_list);

    bool should_continue = true;
    std::vector<std::size_t> colors_mapping;

    for (std::size_t num_colors = 1; num_colors <= num_vertices; ++num_colors)
    {
        PermRepeatGenerator generator(num_vertices, num_colors);
        std::tie(should_continue, colors_mapping) = generator.next();

        for (; should_continue; std::tie(should_continue, colors_mapping) = generator.next())
        {
            bool is_correct_mapping = true;

            auto coordinates = boost::get(coord_t(), adjacency_list);
            for (auto [ei, ei_end] = boost::edges(adjacency_list); ei != ei_end; ++ei)
                if (colors_mapping[boost::get(coordinates, boost::source(*ei, adjacency_list))] ==
                    colors_mapping[boost::get(coordinates, boost::target(*ei, adjacency_list))])
                {
                    is_correct_mapping = false;
                    break;
                }

            if (is_correct_mapping)
                return colors_mapping;
        }
    }

    return colors_mapping;
}

std::vector<std::size_t> Graph::small_mis_optimal_color() const
{
    std::vector<std::size_t> color_mapping;
    return color_mapping;
}