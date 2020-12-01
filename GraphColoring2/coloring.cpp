#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <vector>
#include <ctime>

std::ofstream output_tikz_code("graphColored.tex");
std::ostringstream tikz_code;
std::string key_value_colors[] = {"red", "yellow", "blue"}; 
FILE *fp = fopen("input.txt", "r");

class Graph
{
    int V;
    std::list<int>* adj;
    public:

        Graph(int V)   { this->V = V; adj = new std::list<int>[V]; }
        ~Graph()       { delete [] adj; }
     
        // function to add an edge to graph
        void addEdge(int v, int w);
     
        // Prints greedy coloring of the vertices
        void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void printing_result(int result[], int V)
{
    for (size_t u = 0; u < V; u++)
    {
        tikz_code << "\\AddVertexColor{" << key_value_colors[result[u]] << "}" << "{" << u << "}" << std::endl;
    }
}

void Graph::greedyColoring()
{
    int result[V];
 
    result[0]  = 0;
 
    for (size_t u = 1; u < V; u++)
    {
        result[u] = -1;
    }
 
    bool used_colors[V];
    for (size_t cr = 0; cr < V; cr++)
    {
        used_colors[cr] = false;
    }
 
    for (size_t u = 1; u < V; u++)
    {
        for (auto& i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            if (result[*i] != -1)
            {
                used_colors[result[*i]] = true;
            }
        }
    }
 
        int cr;
        for (cr = 0; cr < V; cr++)
        {
            if (used_colors[cr] == false)
            {
                break;
            }
        }
 
        result[u] = cr;
 
        // Reset the values back to false for the next iteration
        for (auto& i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            if (result[*i] != -1)
            {
                used_colors[result[*i]] = false;
            }
        }
    }
 
    printing_result(result, V);
}