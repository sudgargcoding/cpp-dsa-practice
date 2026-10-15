//https://algo.monster/liteproblems/8

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int myAtoi(string s) {
    int result=0, sign=1, index=0;
    int length=s.size();

    while(index < length && s[index]==' '){
        index++;
    }
    if(s[index]=='-') sign=-1;
    if(s[index]=='-' || s[index]=='+') index++;

    int overflowthreshold=INT_MAX/10;

    while(index<length){
        if(!isdigit(s[index])) break;
        result=10*result + s[index]-'0';
        if(result >= overflowthreshold){
            if(sign==1) result=INT_MAX;
            else if(sign==-1) result=INT_MIN;
        }
        index++;
    }
    return result * sign;
}

int main(){
    string s = " -42";
    int result = myAtoi(s);
    cout << "result=" << result << endl;
    return 0;
}