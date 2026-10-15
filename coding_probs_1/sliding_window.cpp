//https://www.jointaro.com/interviews/questions/longest-substring-without-repeating-characters/?company=grab

#include <iostream>
#include <string>

using namespace std;

int longestSubstringLength(string& input_string){
    unordered_map<char, int> char_to_index_map;
    int window_end, window_start=0;
    int longest_substring_length = 0;

    for(window_end=0;window_end<input_string.length(); window_end++){
        char current_character = input_string[window_end];
        if(char_to_index_map.count(current_character) && char_to_index_map[current_character] >= window_start){
            window_start = char_to_index_map[current_character] + 1;
        }
        char_to_index_map[current_character] = window_end;
        longest_substring_length = max(longest_substring_length, window_end-window_start+1);
    }
    return longest_substring_length;
}