class Solution {
public:
    unordered_map<int, int> u;
    
    int majorityElement(vector<int>& nums) {
        int answer = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            u[nums[i]] += 1;
        }
        
        
        for (auto iter = u.begin(); iter != u.end(); iter++) {
            if (iter->second > nums.size() / 2) {
                answer = iter->first;
                break;
            }
        }
        
        return answer;
    }
};