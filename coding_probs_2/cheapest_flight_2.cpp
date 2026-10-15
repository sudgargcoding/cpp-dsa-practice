#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n]; 
        
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dis(n); 
        for(int i=0;i<n;i++){
            dis[i]=1e9; 
        }

        dis[src]=0; 
        queue<pair<int,pair<int,int>>> pq;

        pq.push({src,{0,0}}); 

        while(!pq.empty()){
            int node=pq.front().first; 
            int step=pq.front().second.first;
            int d=pq.front().second.second;
            pq.pop();

            for(auto &it:adj[node]){
                int newnode=it.first;
                int newd=it.second; 

                if((newd+d<dis[newnode]) && step<=k){
                    dis[newnode]=newd+d;
                    pq.push({newnode,{step+1,newd+d}});
                }
            }
        }

        if(dis[dst]==1e9){
            return -1;
        }
        
        return dis[dst];
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 200}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;

    int result = solution.findCheapestPrice(n, flights, src, dst, k);
    std::cout << "Cheapest price: " << result << std::endl; // Output: Cheapest price: 200
    return 0;
}