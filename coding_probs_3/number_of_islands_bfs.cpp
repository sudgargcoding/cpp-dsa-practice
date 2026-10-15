// https://leetcode.com/problems/number-of-islands/solutions/56589/c-bfsdfs-by-jianchao-li-6sxp/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int>> directions = {{-1,0},{0,-1},{0,1},{1,0}};
        int islands=0;
        queue<pair<int,int>> q;
        int rows = grid.size(); int col = grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1') {
                islands++;
                q.push({i,j});

                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    for (auto dir: directions){
                        int nx = x+dir.first;
                        int ny = y+dir.second;
                        if(nx>=0 && nx<rows && ny>=0 && ny<col && grid[nx][ny]=='1'){
                            q.push({nx,ny});
                            grid[nx][ny]='0';
                        }
                    }
                }
            }}
        }
        return islands;
    }
};
