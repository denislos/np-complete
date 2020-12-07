#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "graph.h"

#include "benchmark/benchmark.h"


static int optimal_color_routine(bool use_brute_force = false)
{
    const std::vector<std::string> traces = {
        "../../GraphColoring/traces/input.txt"
    };

    for (const auto& trace : traces)
    {
        std::ifstream ifs(trace);
        
        std::size_t num_edges, num_vertices;
        ifs >> num_vertices >> num_edges;

        Graph graph(num_vertices);

        for (std::size_t i = 0; i < num_edges; ++i)
        {
            std::size_t va, vb;
            ifs >> va >> vb;
            graph.add_edge(va, vb);
        }

        std::vector<std::size_t> color_mapping;

        if (use_brute_force)
            color_mapping = graph.brute_force_optimal_color();
        else
            color_mapping = graph.small_mis_optimal_color();
    }

    return EXIT_SUCCESS;
}

static void GraphColoring_BruteForceOptimalColor(benchmark::State& state) {
    for (auto _ : state) {
        optimal_color_routine(true);
    }
}

static void GraphColoring_SmallMisOptimalColor(benchmark::State& state) {
    for (auto _ : state) {
        optimal_color_routine(false);
    }
}

BENCHMARK(GraphColoring_BruteForceOptimalColor);
BENCHMARK(GraphColoring_SmallMisOptimalColor);

BENCHMARK_MAIN();
