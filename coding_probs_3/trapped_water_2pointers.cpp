//https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int start=0, end=height.size()-1;
        int leftmax=0, rightmax=0;
        int totalwater=0;

        while(start<end){
            leftmax = max(leftmax, height[start]);
            rightmax = max(rightmax, height[end]);

            if(leftmax < rightmax)
            {
                totalwater+= leftmax - height[start];
                start++;
            }
            else{
                totalwater+= rightmax - height[end];
                end--;
            }
        }
        return totalwater;
    }
};

int main(){
    Solution obj;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int totalwater = obj.trap(height);
    cout << "totalwater=" << totalwater << endl;
}