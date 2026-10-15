//https://leetcode.com/problems/word-ladder/solutions/40707/c-bfs-by-jianchao-li-n5jy/

#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int wordLadder(string start_word, string end_word, vector<string>& word_list){
    unordered_set<string> dict(word_list.begin(), word_list.end());
    queue<string> todo;
    todo.push(start_word);
    int ladder=1;

    while(!todo.empty()){
        int n = todo.size();
        for (int i=0;i<n;i++){
            string word = todo.front();
            todo.pop();
            if(word == end_word) return ladder;

            dict.erase(word);

            for(int j=0;j<word.size();j++) { //no. of chars in the word
                char c=word[j];
                for(int k=0;k<26;k++){
                    word[j]='a'+k;
                    if(dict.find(word) != dict.end()){
                        todo.push(word);
                    }
                }
                word[j]=c;
            }
        }
        ladder++;
    }
    return 0;
}

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList= {"hot","dot","dog","lot","log","cog"};
    int length = wordLadder(beginWord, endWord, wordList);
    cout << "length=" << length << endl;
}