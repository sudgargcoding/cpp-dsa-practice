//https://algo.monster/liteproblems/1105

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int numBooks = books.size();
      
        // dp[i] represents the minimum height of bookshelf to place first i books
        vector<int> dp(numBooks + 1);
        dp[0] = 0; // Base case: no books means zero height
      
        // Iterate through each book position 
        for (int i = 1; i <= numBooks; ++i) {
            // Current book dimensions
            int currentWidth = books[i - 1][0];
            int currentHeight = books[i - 1][1];
          
            // Initialize: place current book on a new shelf
            dp[i] = dp[i - 1] + currentHeight;
          
            // Try placing previous books on the same shelf as current book
            for (int j = i - 1; j > 0; --j) {
                // Add width of book j to current shelf
                currentWidth += books[j - 1][0];
              
                // Check if shelf width constraint is violated
                if (currentWidth > shelfWidth) {
                    break;
                }
              
                // Update maximum height of current shelf
                currentHeight = max(currentHeight, books[j - 1][1]);
              
                // Update minimum total height if placing books j to i on same shelf
                dp[i] = min(dp[i], dp[j - 1] + currentHeight);
            }
        }
      
        return dp[numBooks];
    }
};