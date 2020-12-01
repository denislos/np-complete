
#include "graph.h"

std::vector<int> Graph::greedy_color(int num_colors)
{
    std::vector<int> colors_mapping(V, -1);
    colors_mapping[0] = 0;

    std::vector<bool> used_colors(num_colors, false);
 
    for (std::size_t vertex = 1; vertex < V; vertex++)
    {
        for (const auto& adj_vertex : adjacency_lists[vertex])
            if (colors_mapping[adj_vertex] != -1)
                used_colors[colors_mapping[adj_vertex]] = true;

        int first_used_color = -1;
        for (int color = 0; color < num_colors; ++color)
            if (!used_colors[color]) {
                first_used_color = color;
                break;
            }

        colors_mapping[vertex] = first_used_color;
 
        // Reset the values back to false for the next iteration
        for (auto& adj_vertex : adjacency_lists[vertex])
            if (colors_mapping[adj_vertex] != -1)
                used_colors[colors_mapping[adj_vertex]] = false;
    }
 
    return colors_mapping;
}