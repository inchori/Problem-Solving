class Solution {
public:
    int answer;
    void dfs(vector<int> &nums, int S, int depth, int sum) {
        if (depth == nums.size()) {
            if (sum == S) answer++;
        }
        else {
            dfs(nums, S, depth + 1, sum + nums[depth]);
            dfs(nums, S, depth + 1, sum - nums[depth]);
        }
        
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
       dfs(nums, S, 0, 0);
        return answer;
    }
};