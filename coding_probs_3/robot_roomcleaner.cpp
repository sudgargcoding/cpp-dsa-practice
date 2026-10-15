//https://algo.monster/liteproblems/489

#include <vector>
#include <iostream>

using namespace std;

int roomcleaner(vector<vector<int>>& grid){
    vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
    int rows = grid.size();
    int cols = grid[0].size();
    stack<pair<int,int>> st;
    int numrooms = 0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j] == 1){
                grid[i][j]=0;
                numrooms++;
                st.push({i,j});
            }
            while(!st.empty()){
                int x=st.top().first;
                int y=st.top().second;
                st.pop();
                for(auto dir: directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if(nx>=0 && nx < rows && ny>=0 && ny<cols && grid[nx][ny]==1){
                        grid[nx][ny]=0;
                        st.push({nx,ny});
                        numrooms++;
                    }
                }
            }
        }
    }
    return numrooms;
}

int main(){
    vector<vector<int>> grid = {{1,1,1,1},{1,0,1,0},{1,1,1,1}};
    int rooms = roomcleaner(grid);
    cout << "Rooms=" << rooms << endl;
}
