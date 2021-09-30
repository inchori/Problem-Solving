class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int maxReach = 0;
        int currReach = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, nums[i] + i);
            
            if (i == currReach) {
                jumps++;
                currReach = maxReach;
            }
        }
        
        return jumps;
    }
};