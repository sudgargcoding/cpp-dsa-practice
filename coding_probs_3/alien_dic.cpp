//https://leetcode.com/problems/verifying-an-alien-dictionary/solutions/3129154/c-solution-convert-word-into-normal-orde-xhon/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool isAlienSorted(vector<string>& words, string order){
    unordered_map<char,char> mp;
    for(int i=0;i<26;i++){
        mp[order[i]]='a'+i;
    }

    for(int j=0;j<words.size();j++){
        for(int k=0;k<words[j].size();k++){
            words[j][k]=mp[words[j][k]];
        }
    }
    return is_sorted(words.begin(), words.end());
}

int main(){
    vector<string> words = {"hello","leetcode"};
    string order ="hlabcdefgijkmnopqrstuvwxyz" ;
    bool value = isAlienSorted(words, order);
    cout << "value=" << value << endl;
}