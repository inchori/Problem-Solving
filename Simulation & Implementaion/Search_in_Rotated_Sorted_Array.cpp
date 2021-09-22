class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> u;
        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            u[nums[i]] = i;
        }
        
        if (u.find(target) != u.end()) {
            answer = u[target];
        } else answer = -1;
        
        return answer;
    }
};