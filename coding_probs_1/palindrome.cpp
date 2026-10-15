// https://algo.monster/liteproblems/5

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindomeSubstring(string input){
    int length = input.length();
    if(length<2) return "";

    int start=0, end=0;
    int max_length=1;
    vector<vector<bool>> dp(length, vector<bool>(length,false) );

    for(int i=0;i<length;i++){
        dp[i][i] = true;
        for(int j=0;j<i;j++){
            if(input[i] == input[j] && ((i-j <= 2)|| dp[i-1][j+1])){
                dp[i][j] = true;
                if(max_length<i-j+1){
                    max_length=i-j+1;
                    start=i;
                    end=j;
                }
            }
        }
    }
    return input.substr(start,end-start+1);

}