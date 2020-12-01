#include <iostream>
#include <cstdlib>

#include "graph.h"

#include "benchmark/benchmark.h"


static int solve_coloring_problem(int num_colors)
{
    FILE* input_file = fopen("../../GraphColoring/input.txt", "r");
    if (input_file == NULL) {
        std::perror("Cannot open input file");
        std::exit(EXIT_FAILURE);
    }

    std::size_t V = 0;

    std::fscanf(input_file, "%lu\n", &V);

    Graph graph(V);

    std::size_t va, vb;
    while (std::fscanf(input_file, "%lu %lu\n", &va, &vb) != EOF)
        graph.add_edge(va, vb);

    auto color_mapping = graph.brute_force_color(num_colors);

    /*
    std::cout << "Number of colors: " << num_colors << "\n";
    for (std::size_t vertex = 0; vertex < V; ++vertex)
        std::cout << "Vertex: " << vertex << " Color: " << color_mapping[vertex] << "\n";

    std::cout << std::endl << std::endl;
    */

    fclose(input_file);

    return EXIT_SUCCESS;
}

static void Benchmark_GraphColoring(benchmark::State& state) {
    for (auto _ : state) {
        solve_coloring_problem(state.range(0));
    }
}

BENCHMARK(Benchmark_GraphColoring)->DenseRange(3, 5, 1);

BENCHMARK_MAIN();
