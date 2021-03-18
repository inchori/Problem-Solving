#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        for (int x = 0; x < n; x++) {
            dp[x][x] = true;
            if (x == n - 1) break;
            dp[x][x + 1] = (s[x] == s[x + 1]);
        }

        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
            }
        }

        int max = 0;
        string maxstr = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j] == true && j - i + 1 > max) {
                    max = j - i + 1;
                    maxstr = s.substr(i, j - i + 1);
                }
            }
        }

        return maxstr;
    }
};