class Solution {
public:
    int dp[505][505];
    
    int minDistance(string word1, string word2) {
        if (word1 == word2) {
            return 0;
        }
        
        int m = word1.length();
        int n = word2.length();
        
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= n; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};