#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Adjacency list representation of a graph
class Graph
{
    int V; // No. of vertices
    vector<list<int>> adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = vector<list<int>>(V);
    }

    // Add w to v's list
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    int getV() 
    {
        return V;
    }

    vector<list<int>> getAdj()
    {
        return adj;
    }
};