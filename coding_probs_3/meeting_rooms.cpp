//https://algo.monster/liteproblems/253

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minMeetingRooms(vector<vector<int>>& intervals) {
    int maxendtime=0;
    for(auto& interval: intervals){
        maxendtime = max(maxendtime, interval[1]);
    } 
    vector<int> diffarray(maxendtime+1,0);

    for(auto& interval: intervals){
        diffarray[interval[0]]++;
        diffarray[interval[1]]--;
    }

    int maxrooms = 0;
    int currentrooms=0;
    for(int index: diffarray){
        currentrooms+=index;
        maxrooms = max(maxrooms, currentrooms);
    }
    return maxrooms;
}