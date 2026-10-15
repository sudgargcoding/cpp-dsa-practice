//https://www.jointaro.com/interviews/questions/subarray-sum-equals-k/?company=grab

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int subarraySum(int k , vector<int>& nums){
        if (nums.size() == 0) return 0;

        int count = 0;
        unordered_map<int, int> sumFrequency;

        for(int value=0; value < nums.size(); value++) {
            int currentSum;
            currentSum += nums[value] ;
            if (sumFrequency.find(currentSum - k) != sumFrequency.end()) {
                count += sumFrequency[currentSum - k];
            }
           
            sumFrequency[currentSum]++;
        }

        return count;
    }
};