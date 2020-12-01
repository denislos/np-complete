#pragma once

#include <vector>
#include <list>

class Graph
{
public:
    explicit Graph(std::size_t V)
        : V(V)
        , adjacency_lists(std::vector<std::list<std::size_t>>(V))
    { }
    
    void add_edge(std::size_t v, std::size_t w) {
        adjacency_lists[v].push_back(w);
        adjacency_lists[w].push_back(v);
    }
     
    std::vector<int> greedy_color(int num_colors);

private:
    std::size_t V = 0;

    std::vector<std::list<std::size_t>> adjacency_lists; 
};