//https://www.jointaro.com/interviews/questions/simplify-path/?company=grab

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
    string simplerPath(string input_string){
        stringstream stream(input_string);
        string segment;
        vector<string> stack;

        while(getline(stream,segment,'/')){
            if((segment == ".") || segment.empty()) continue;
            if((segment == "..") && !stack.empty()) 
                stack.pop_back();
            else 
                stack.push_back(segment);
        }

        if(stack.empty())
         return "/";

        string simplified_path;
        for(const string& dir : stack){
            simplified_path += "/" + dir;
        }

        return simplified_path;
    }
};

