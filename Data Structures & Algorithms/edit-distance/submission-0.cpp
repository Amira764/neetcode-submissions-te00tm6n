class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // dp[i][j] will store the edit distance for word1[0...i-1] and word2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // Fill the base cases
        for (int i = 0; i <= n; i++) dp[i][0] = i; // Deleting all from word1
        for (int j = 0; j <= m; j++) dp[0][j] = j; // Inserting all for word2

        // Fill the rest of the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no new operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters differ, pick the best of 3 operations:
                    // dp[i-1][j]   -> Deletion
                    // dp[i][j-1]   -> Insertion
                    // dp[i-1][j-1] -> Replacement
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }

        return dp[n][m];
    }
};