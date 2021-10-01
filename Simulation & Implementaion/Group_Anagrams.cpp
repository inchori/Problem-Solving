class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<string> temp;
        unordered_map<string, vector<string>> u;
        temp = strs;
        for (int i = 0; i < strs.size(); i++) {
            sort(temp[i].begin(), temp[i].end());
        }
        
        for (int i = 0; i < strs.size(); i++) {
            u[temp[i]].push_back(strs[i]);
        }
        
        for (auto iter = u.begin(); iter != u.end(); iter++) {
            answer.push_back(iter->second);
        }
        return answer;
    }
};