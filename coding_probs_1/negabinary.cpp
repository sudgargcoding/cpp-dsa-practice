//https://www.jointaro.com/interviews/questions/adding-two-negabinary-numbers/?company=grab
// Solution is not from this site, but the one from leetcode

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> sumNegobinaryNumbers(vector<int>& arr1, vector<int>& arr2){
    int carry=0;
    int length_arr1 = arr1.size()-1;
    int length_arr2 = arr2.size()-1;
    vector<int> ans;

    while(length_arr1 >=0 || length_arr2 >=0 || carry!=0){
        carry = carry + arr1[length_arr1--] + arr2[length_arr2--];
        ans.push_back(carry&1);
        carry = -(carry>>1);
    }
    while(ans.size()>1 && ans.back()==0){
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

#if 0
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) carry += arr1[i--];
            if (j >= 0) carry += arr2[j--];

            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }

        while (ans.size() > 1 && ans.back() == 0)
            ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans;
    }
#endif

int main(){
    vector<int> arr1 = {1,1,1,1,1};
    vector<int> arr2 = {1,0,1};
    vector<int> sol = sumNegobinaryNumbers(arr1, arr2);
   // vector<int> sol = addNegabinary(arr1, arr2);

    for (int x : sol)
        cout << x << ", " << endl;
}