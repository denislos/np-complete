cmake_minimum_required(VERSION 3.10)

project(GraphColoring)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)
find_package(Boost)

FILE(GLOB SRCS
    "src/graph.cpp"
    "src/coloring_bench.cpp"
)

set(EXECUTABLE coloring_bench)

add_executable(${EXECUTABLE} ${SRCS})
target_compile_options(${EXECUTABLE} PUBLIC -O3 -Wall -Werror -Wextra)
target_link_libraries(${EXECUTABLE} PUBLIC benchmark::benchmark)