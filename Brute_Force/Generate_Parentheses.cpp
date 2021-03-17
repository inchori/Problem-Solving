class Solution {
public:
    
    vector<string> answer;
    
    void dfs(string now, int n, int open, int close) {
        if (now.length() == 2 * n) {
            answer.push_back(now);
            return;
        }
        if (open < n) dfs(now + "(", n, open + 1, close);
        if (open > close) dfs(now + ")", n, open, close + 1);
    }
    
    vector<string> generateParenthesis(int n) {
        dfs("", n, 0, 0);
        return answer;
    }
};