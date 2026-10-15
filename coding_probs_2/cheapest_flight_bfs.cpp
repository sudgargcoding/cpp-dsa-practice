#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create a graph representation of the flights
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            graph[u].emplace_back(v, price);
        }

        // Min-heap to store (cost, current city, stops)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, src, 0}); // {cost, city, stops}

        while (!minHeap.empty()) {
            auto [cost, city, stops] = minHeap.top();
            minHeap.pop();

            // If we reach the destination city
            if (city == dst) {
                return cost;
            }

            // If we can still make more stops
            if (stops <= k) {
                for (const auto& [nextCity, price] : graph[city]) {
                    minHeap.push({cost + price, nextCity, stops + 1});
                }
            }
        }

        return -1; // If destination is not reachable within k stops
    }
};

void main() {
    Solution solution;
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;

    int result = solution.findCheapestPrice(n, flights, src, dst, k);
    std::cout << "Cheapest price: " << result << std::endl; // Output: Cheapest price: 200
}