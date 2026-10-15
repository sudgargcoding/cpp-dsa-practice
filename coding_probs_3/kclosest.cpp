//https://algo.monster/liteproblems/973

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> kclosest(vector<vector<int>> points, int k){
  sort(points.begin(), points.end(),[](const vector<int> point1, const vector<int>& point2){
    double distance1 = hypot(point1[0], point1[1]);
    double distance2 = hypot(point2[0], point2[1]);
    return distance1 < distance2;
  });
  return vector<vector<int>>(points.begin(), points.begin()+k);
}
