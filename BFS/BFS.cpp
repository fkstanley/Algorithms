#include <iostream>
#include <queue>
#include <vector>

#include "../Graph/Graph.cpp"

using namespace std;

void BFS(Graph g, int start)
{
    // Set all vertices to unvisited
    bool visited[g.getV()];
    for (int i = 0; i < g.getV(); ++i)
    {
        visited[i] = false;
    }

    queue<int> queue;
    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
    {
        start = queue.front();
        cout << start << " ";
        queue.pop();

        // Get all adjacent vertices
        // If vertex is unvisited, add it to the queue
        vector<list<int>> adj = g.getAdj();
        for (auto i : adj[start])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

int main() {
    Graph graph(6);
    graph.addEdge(0,1); graph.addEdge(0,2);
    graph.addEdge(1,0); graph.addEdge(1,3); graph.addEdge(1,4);
    graph.addEdge(2,0); graph.addEdge(2,4);
    graph.addEdge(3,1); graph.addEdge(3,4); graph.addEdge(3,5);
    graph.addEdge(4,1); graph.addEdge(4,2); graph.addEdge(4,3); graph.addEdge(4,5);
    graph.addEdge(5,3); graph.addEdge(5,4);

    BFS(graph, 0);
}