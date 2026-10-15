#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
vector<int> v;
v.push_back(x);
v.pop_back();

v.size(); v.empty();

v.front(); v.back();

sort(v.begin(), v.end());
reverse(v.begin(), v.end());

unordered_map<int,int> mp;
mp[x]++;
mp.count(x);mp.erase(x);
for(auto& [x,y]: mp)

unordered_set<int> s;
priority_queue<int> pq; //max heap
priority_queue<int,vector<int>,greater<int>> pq2; //min heap

queue<int> q;
q.push(x); q.pop();
q.front(); q.back();

stack<int> st;
st.top(); st.pop();
st.push(x);

void bfs(const vector<vector<int>>& graph, int startNode){
    queue<int> q;
    vector<bool> visitedNode(graph.size());

    q.push(startNode);
    visisted(startNode) = true;

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        for(auto& node:graph[currentNode]){
           if(!visitedNode[node]){
                visitedNode[node] = true;
                q.push(node);
           }
        }
    }
}

void dfs(int startNode, const vector<vector<int>>& graph){
    stack<int> st;
    vector<bool> visitedNode(graph.size());

    visitedNode[startnode]=true;
    st.push(startNode);

    while(!st.empty()){
        int currentNode = st.top();
        st.pop();
        for(auto& node: graph[currentNode]){
            if(!visitedNode[node]){
                visitedNode[node] = true;
                st.push(node);
            }
        }
    }
}

int numIslands(vector<vector<char>>& graph){
    int rows = graph.size();
    int cols = graph[0].size();
    int islands=0;
    stack<pair<int,int>> st;
    vector<pair<int,int> directions = {{-1,0},{0,-1},{0,1},{1,0}};

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(graph[i][j]=='1'){
                graph[i][j]='0';
                st.push({i,j});
                islands++;
            }
            while(!st.empty()){
                auto [x,y] = st.pop();
                for(auto dir:directions){
                    int nx = x+dir.first;
                    int ny = y+dir.second;
                    if(nx>=0 && x<rows && ny>=0 && y<cols && graph[nx][ny]=='1'){
                        graph[nx][ny]='0';
                        st.push({x,y});
                    }
                }
            }
        }
    }
    return islands;
}

void bst(root){
    while(root){
        if(root->val == target)
            return root;
        if(root->val > target){
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}

void binarySearch(string& input){
    int left=0, right=input.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(input[mid]==target) return mid;
        if(input[mid]<target){
            left = mid+1;
        }
        else
            right=mid-1;
    }
}

int longestSubstring(const string& input){
    int window_end=0, window_start=0, length=0;
    unordered_map<char,int> mp;
    
    for(window_end=0;window_end<input.length();window_end++){
        char character = input[window_end];
        if(mp.count(character) && mp[character] >= window_start){
            window_start=mp[character]+1;
        }
        mp[character] = window_end;
        length=max(length, window_end-window_start+1);
    }
    return length;
}

return 0;
}