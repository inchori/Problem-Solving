#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> answer;
    vector<string> temp;
    
    bool isPalindrome(vector<string> &temp) {
        bool flag = true;
        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp[i].length() / 2; j++) {
                if (temp[i][j] != temp[i][temp[i].length() - 1 - j]) {
                    flag = false;
                }
            }
        }
        if (!flag) return false;
        return true;
    }
    
    void dfs(string s, int depth) {
        if (depth == s.length()) {
            if (isPalindrome(temp)) {
                answer.push_back(temp);
                return;
            } else return;
        }
        
        string now = "";
        now += s[depth];
        temp.push_back(now);
        dfs(now, depth + 1);
        temp.pop_back();
        temp[temp.size() - 1] += s[depth];
        dfs(now, depth + 1);
    }
    
    vector<vector<string>> partition(string s) {
        string now = "";
        now += s[0];
        temp.push_back(now);
        dfs(s, 1);
        return answer;
    }
};