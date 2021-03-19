class Solution {
public:
    vector<int> temp;
    vector<vector<int>> answer;
    bool visited[35];
    void dfs(int depth, vector<int>& candidates, int target, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            answer.push_back(temp);
            return;
        }

        for (int i = depth; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            sum += candidates[i];
            dfs(i, candidates, target, sum);
            sum -= candidates[i];
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, candidates, target, 0);
        return answer;
    }
};