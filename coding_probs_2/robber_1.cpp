#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int loop=2;loop<n;loop++){
            dp[loop]=max(dp[loop-1],nums[loop]+dp[loop-2]);
        }
        return dp[n-1];
    }
};