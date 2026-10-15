#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform optimized BFS
void optimizedBFS(int startNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    
    // Mark the starting node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        
        // Process current node (e.g., print it)
        cout << currentNode << " ";

        // Traverse all adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark BEFORE pushing to avoid redundant queue entries
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Number of vertices
    int V = 5;
    
    // Construct graph using Adjacency List
    vector<vector<int>> adjList(V);
    
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0};
    adjList[3] = {1};
    adjList[4] = {1};

    // Keep track of visited nodes to prevent cycles
    vector<bool> visited(V, false);

    cout << "BFS Traversal starting from node 0: ";
    // Loop to handle disconnected graphs
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            optimizedBFS(i, adjList, visited);
        }
    }

    return 0;
}
