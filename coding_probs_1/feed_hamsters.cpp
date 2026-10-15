// https://www.jointaro.com/interviews/questions/minimum-number-of-food-buckets-to-feed-the-hamsters/?company=grab

#include <iostream>
#include <string>

using namespace std;

int minimumBuckets(string hamsters){
    int count=0;
    for(int index=0;index<hamsters.size();index++){
        if(hamsters[index] == 'H'){
            if(index >0 && hamsters[index-1] == '.') {
                hamsters[index-1] = 'B';
                count++;
            }
            else if(index < hamsters.size()-1 && hamsters[index+1] == '.') {
                hamsters[index+1] = 'B';
                count++;
            }
            else {
                return -1; //hamsters can't be fed
            }
        }
    }
    return count;
}