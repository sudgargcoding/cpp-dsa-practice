//https://www.jointaro.com/interviews/questions/reconstruct-a-2-row-binary-matrix/?company=grab

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reconstruct_matrix(vector<int>& columns, int lower, int upper){
    int number_of_columns = columns.size();
    vector<vector<int>> result(2,vector<int>(number_of_columns,0));
    for(int loop=0; loop<number_of_columns;loop++){
        if(columns[loop]==2){
            result[1][loop] = 1;
            result[0][loop] = 1;
            lower--;
            upper--;
        }
        else if(columns[loop]==0){
            result[1][loop] = 0;
            result[0][loop] = 0;
        }
        else if(columns[loop]==1){
            if(lower>0){
                result[1][loop]==1;
                result[0][loop]==0;
                lower--;
            }
            else{
                result[1][loop]==0;
                result[0][loop]==1;
                upper--;
            }
        }
    }
    if(upper<0 || lower <0) return {};
    for(int i=0;i<number_of_columns;i++){
        if(columns[i] != (result[0][i] + result[1][i])) return{};
    }
    return result;
}