class Solution {
public:
    vector<int> temp;
    vector<vector<int>> answer;
    void dfs(vector<int>& candidates, int target, int sum, int now) {
        if (sum > target) return;
        
        if (sum == target) {
            answer.push_back(temp);
        }
        
        for (int i = now; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target, sum, i);
            sum -= candidates[i];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return answer;
    }
};