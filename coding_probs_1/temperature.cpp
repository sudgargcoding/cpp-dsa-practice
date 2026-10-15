//https://www.jointaro.com/interviews/questions/daily-temperatures/?company=grab

#include <iostream>
#include <stack>

using namespace std;

class Solution {
    vector<int> higherTemperature(vector<int>& temperature){
        vector<int> answer(temperature.size(),0);
        stack<int> stack;

        stack.push(temperature[0]);

        for(int loop=1;loop < temperature.size(); loop++){
            while(!stack.empty()){
                int prev_temp = temperature[stack.top()];
                if(prev_temp < temperature[loop]){
                    answer[stack.top()] = loop - stack.top();
                    stack.pop();
                }
                else
                    stack.push(loop);
            }
        }
        return answer;
    }
};