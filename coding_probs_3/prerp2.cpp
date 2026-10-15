#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>
#include <set>

using namespace std;

int lcs(int m, int n, vector<vector<int>>& memo, string& word1, string& word2){
    if(m==0 || n==0) return 0;
    if(memo[m][n]!-1) return memo[m][n];

    if(word1[m-1] == word2[n-1]){
        memo[m][n]=1+lcs(memo[m-1][n-1], m-1. n-1, word1, word2);
    }
    memo[m][n]=max(lcs(memo[m][n-1]),lcs(memo[m-1][n]))

    return memo[m][n];
}