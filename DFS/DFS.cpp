#include <iostream>
#include <stack>
#include <vector>

#include "../Graph/Graph.cpp"

void DFS(Graph g, int start)
{
    // Set all vertices to unvisited
    bool visited[g.getV()];
    for (int i = 0; i < g.getV(); ++i)
    {
        visited[i] = false;
    }

    // They key difference to BFS is that a stack is used here
    stack<int> stack;
    visited[start] = true;
    stack.push(start);

    while (!stack.empty())
    {
        start = stack.top();
        cout << start << " ";
        stack.pop();

        // Get all adjacent vertices
        // If vertex is unvisited, add it to the queue
        vector<list<int>> adj = g.getAdj();
        for (auto i : adj[start])
        {
            if (!visited[i])
            {
                visited[i] = true;
                stack.push(i);
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

    DFS(graph, 0);
}