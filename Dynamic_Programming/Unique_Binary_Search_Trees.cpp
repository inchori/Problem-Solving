class Solution {
public:
    
    int dp[25];
    
    int numTrees(int n) {
        dp[0] = dp[1] = 1;
    
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};