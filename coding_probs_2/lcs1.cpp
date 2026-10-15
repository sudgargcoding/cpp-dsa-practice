#include <iostream>   
#include <string>   
#include <algorithm>  
using namespace std;

// Returns length of LCS for s1[0..m-1], s2[0..n-1]
int lcsRec(string &s1, string &s2, int m, int n, vector<vector<int>> &memo) {

    // Base Case
    if (m == 0 || n == 0)
        return 0;

    // Already exists in the memo table
    if (memo[m][n] != -1)
        return memo[m][n];

    // Match
    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + lcsRec(s1, s2, m - 1, n - 1, memo);

    // Do not match
    return memo[m][n] = max(lcsRec(s1, s2, m, n - 1, memo), lcsRec(s1, s2, m - 1, n, memo));
}
int lcs(string &s1,string &s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return lcsRec(s1, s2, m, n, memo);
}

int main() {
    string s1 = "sudhanshu";
    string s2 = "sid";
    cout << lcs(s1, s2) << endl;
    return 0;
}