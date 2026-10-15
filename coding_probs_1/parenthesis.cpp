//https://www.jointaro.com/interviews/questions/valid-parentheses/?company=grab

#include <iostream>
#include <stack>

using namespace std;

class Solution {
    bool isValid(string& input_string){
        stack<char> open_parenthesis;
        for(char parser : input_string){
            if(parser=='{' || parser== '[' || parser == '('){
                open_parenthesis.push(parser);
            }
            else if((parser=='}' || parser== ']' || parser == ')') && open_parenthesis.empty()) return false;
            
            char token = open_parenthesis.top();
            if((parser=='}' && token != '{') || 
               (parser==']' && token != '[') ||
               (parser==')' && token != '(')){
                return false;
               }
            open_parenthesis.pop();   
        }

        if(!open_parenthesis.empty()) return false;
        else return true;
    }  
};