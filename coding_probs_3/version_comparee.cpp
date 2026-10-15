//https://algo.monster/liteproblems/165

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compareVersion(string version1, string version2){
    int length1 = version1.size();
    int length2 = version2.size();
    int index1=0, index2=0;
    int revision1=0, revision2=0;

    while(index1<length1 || index2<length2){
        while(index1<length1 && version1[index1] != '.'){
            revision1 = 10*revision1 + version1[index1]-'0';
            index1++;
        }
        while(index2<length2 && version2[index2] != '.'){
            revision2 = 10*revision2 + version2[index2]-'0';
            index2++;
        }

        if (revision1 > revision2) return 1;
        else if(revision1 < revision2) return -1;

        if(index1 < length1) index1++;
        if(index2 < length2) index2++;
    }
    return 0;
}

int main(){
    string string1="1.1.3";
    string string2="1.2.0";
    int result = compareVersion(string1, string2);
    cout << "result = " << result << endl;
    return 0;
}