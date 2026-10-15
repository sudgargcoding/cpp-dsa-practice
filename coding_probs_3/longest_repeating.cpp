//https://algo.monster/liteproblems/1062

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.length();

        // dp[i][j] represents the length of common substring ending at s[i] and s[j]
        // where i > j (to ensure we're comparing different positions)
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        int maxLength = 0;

        // Iterate through all pairs of positions (i, j) where i > j
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // If characters at positions i and j match
                if (s[i] == s[j]) {
                    // If j > 0, extend the previous matching substring
                    // Otherwise, start a new matching substring of length 1
                    dp[i][j] = 1 + (j > 0 ? dp[i - 1][j - 1] : 0);

                    // Update the maximum length found so far
                    maxLength = max(maxLength, dp[i][j]);
                }
                // If characters don't match, dp[i][j] remains 0 (already initialized)
            }
        }

        return maxLength;
    }
};