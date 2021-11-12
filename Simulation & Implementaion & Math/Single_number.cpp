class Solution {
public:
    unordered_map<int, int> u;
    
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int answer = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            u[nums[i]] += 1;
        }
        
        for (auto iter = u.begin(); iter != u.end(); iter++) {
            if (iter->second == 1) {
                answer = iter->first;
                break;
            }
        }
        
        return answer;
    }

    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};