
#include "graph.h"
#include "perm_repeat_generator.h"

#include <tuple>
#include <iostream>

std::vector<std::size_t> Graph::brute_force_color(std::size_t num_colors)
{
    PermRepeatGenerator generator(V, num_colors);

    auto [should_continue, colors_mapping] = generator.next();

    for (; should_continue; std::tie(should_continue, colors_mapping) = generator.next()) {
        bool is_correct_mapping = true;

        for (std::size_t vertex = 0; vertex < V; ++vertex)
            for (const auto adjacent_vertex : adjacency_lists[vertex])
                if (colors_mapping[vertex] == colors_mapping[adjacent_vertex]) {
                    is_correct_mapping = false;
                    goto end_iteration;      
                }

        end_iteration:
        if (is_correct_mapping)
            return colors_mapping;
    }

    return colors_mapping;
}