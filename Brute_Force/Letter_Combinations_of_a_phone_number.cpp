class Solution {
public:
    map<string, string> phone = {{"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"}, {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}};
    vector<string> answer;
    
    void dfs(string now, string digits) {
        if (digits.length() == 0) {
            answer.push_back(now);
            return;
        }
        string digit = digits.substr(0, 1);
        string letters = phone[digit];
        for (int i = 0; i < letters.length(); i++) {
            char letter = letters[i];
            dfs(now + letter, digits.substr(1));
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() != 0) dfs("", digits);
        return answer;
    }
}