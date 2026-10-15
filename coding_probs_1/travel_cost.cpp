//https://www.jointaro.com/interviews/questions/minimum-cost-for-tickets/?company=grab

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int travel_cost_finder(vector<int>& travel_days, vector<int>& cost) {
        int num_travel_days = travel_days.size();
        int last_day = travel_days[num_travel_days-1];
        vector<int> cost_so_far(last_day+1, 0);
        bool travel_today=false;
        
        for(int travel_day=1;travel_day<=last_day;travel_day++){
            for(auto day : travel_days){
                if(day == travel_day){
                    travel_today=true;
                    break;
                }
            }
            if(travel_today){
                int cost_option_1day = cost_so_far[max(0,travel_day-1)] + cost[0];
                int cost_option_7days = cost_so_far[max(0,travel_day-7)] + cost[1];
                int cost_option_30days = cost_so_far[max(0,travel_day-30)] + cost[2];

                cost_so_far[travel_day] = min(cost_option_1day, cost_option_7days, cost_option_30days);
            }
            else {
                cost_so_far[travel_day] = cost_so_far[travel_day-1];
            }
            travel_today=false;
        }
        return cost_so_far[last_day];
    }
};