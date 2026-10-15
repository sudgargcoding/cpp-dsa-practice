
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int rows=grid.size();
        int col=grid[0].size();
        vector<pair<int,int>> directions={{-1,0},{0,-1},{0,1},{1,0}};
        stack<pair<int,int>> s;

        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1') {
                    grid[i][j]='0';
                    islands++;
                    s.push({i,j});
                    while(!s.empty()){
                        auto [x,y] = s.top();
                        for(auto dir:directions){
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if(nx>=0 && nx<rows && ny>=0 && ny<col && grid[nx][ny]=='1'){
                                grid[nx][ny]='0';
                                s.push({nx,ny});
                            }
                        }
                    }
            }
        }
        return islands;
    }
};