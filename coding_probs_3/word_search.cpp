//https://algo.monster/liteproblems/212

#include <iostream>
#include <vector>

using namespace std;

class Trie {
    public:
    vector<Trie*> child;
    int wordidx;
    Trie() : child(26, nullptr), wordidx(-1) {}

    void insert(const string& word, int index){
        Trie *cur = this;
        for(char c: word){
            int idx = c-'a';
            if(!cur->child[idx]){
                cur->child[idx] = new Trie();
            }
            cur = cur->child[idx];
        }
        cur->wordidx = index;
    }
};

class Solution{
    private:
    vector<string> result;
    Trie* obj;
    void dfs(vector<vector<char>>& board, vector<string>& word, Trie* node, int row, int col){
       char ch = board[row][col];
       int idx = ch -'a';

       if(!node->child[idx]) return;
       node = node->child[idx];

       if(node->wordidx != -1){
            result.emplace_back(word[node->wordidx]);
            node->wordidx = -1;
       }

       board[row][col]='#';
       int dir[5] = {-1,0,1,0,-1}; //neighbors - up, right, down, left

       for(int i=0;i<4;i++){
            int nx = row+dir[i];
            int ny = col+dir[i+1];
            if(nx>=0 && nx < board.size() && ny>=0 && ny < board[0].size() && board[nx][ny]!='#'){
                dfs(board,word,node,nx,ny);
            }
       }
       board[row][col] = ch;
    }

    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        obj = new Trie();
        for(int i=0;i<words.size();i++){
            obj->insert(words[i], i);
        }
        int rows = board.size();
        int cols = board[0].size();

        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                dfs(board, words, obj, j, k);
            }
        }

        printresult(result);
    }

    void printresult(vector<string>& result){
        for(string word: result){
            cout << word << endl;
        }
    }
};

int main(){
    Solution obj;
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    obj.findWords(board, words);
    return 1;
}