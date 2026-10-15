//https://algo.monster/liteproblems/937

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> reorderLogFiles(vector<string>& logs){
    stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2){
        int spacePos1 = log1.find(' ');
        int spacePos2 = log2.find(' ');

        string identifier1 = log1.substr(0,spacePos1);
        string identifier2 = log2.substr(0,spacePos2);

        string content1 = log1.substr(spacePos1 + 1);
        string content2 = log2.substr(spacePos2 + 1);

        bool isletter1 = isalpha(content1[0]);
        bool isletter2 = isalpha(content2[0]);

        if(isletter1 && isletter2) {
            if(content1 != content2){
                return content1 < content2;
            }
            return identifier1 < identifier2;
        }
        return isletter1 > isletter2; 

    });
    return logs;
}

int main(){
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> results = reorderLogFiles(logs);
    for (string s: logs){
        cout << s << endl;
    }
    return 0;
}
