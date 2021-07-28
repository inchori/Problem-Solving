class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        unordered_set<char> set;
        int i = 0, j = 0;
        while (i < s.length() && j < s.length()) {
            if (set.find(s[i]) == set.end()) {
                set.insert(s[i++]);
                answer = max(answer, i - j);
            } else {
                set.erase(s[j++]);
            }
        }
        return answer;
    }
};