//https://algo.monster/liteproblems/224

#include <stack>
#include <string>
#include <iostream>

using namespace std;

int calculate(string s) {
    int n = s.size();
    int result=0, prevresult=0;
    stack<int> st;int num=0;
    int sign=1, prevsign=1;

    for(int i=0;i<n;i++){
        char ch=s[i];
        if(isdigit(ch)){
            num=0;
            while(i<n && isdigit(s[i])){
                num = 10*num + s[i]-'0';
                i++;
            }
            i--;
            result = result + sign * num;
        }else if(ch == '+'){
            sign=1;
        }else if(ch == '-'){
            sign=-1;
        }else if(ch == '(') {
            st.push(result);
            st.push(sign);

            //reset for next iteration
            result=0;
            sign=1;
        }else if(ch == ')'){
            prevsign = st.top();
            st.pop();
            prevresult=st.top();
            st.pop();
            result = prevresult + prevsign * result;
        }
    }
    return result;
}

int main(){
    string s="2-(3+4)";
    int result = calculate(s);
    cout << "result = " << result << endl;
}