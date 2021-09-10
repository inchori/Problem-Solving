class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int idx = 0;
        
        do {
            if (idx == 1) {
                break;
            }
            
            idx++;
            
        } while (next_permutation(nums.begin(), nums.end()));
    }
};