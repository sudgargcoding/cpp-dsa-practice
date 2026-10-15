#include <iostream>
#include <vector>
#include <stack>

// Graph represented as an Adjacency List for optimal O(V + E) traversal
void optimizedDFS(const std::vector<std::vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    std::vector<bool> visited(numNodes, false);
    std::stack<int> s;

    s.push(startNode);
    visited[startNode] = true;

    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();

        // Process the current node here (e.g., print it)
        std::cout << currentNode << " ";

        // Traverse all neighbors
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph initialization with 5 vertices (0 to 4)
    std::vector<std::vector<int>> graph = {
        {1, 2},    // Node 0 connects to 1, 2
        {0, 3, 4}, // Node 1 connects to 0, 3, 4
        {0},       // Node 2 connects to 0
        {1},       // Node 3 connects to 1
        {1}        // Node 4 connects to 1
    };

    std::cout << "Optimized DFS Traversal starting from node 0: ";
    optimizedDFS(graph, 0);
    std::cout << std::endl;

    return 0;
}
