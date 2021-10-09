class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = 0, cnt = 0;
        int left = 0, right = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) cnt++;
            else cnt = 0;
            answer = max(answer, cnt);
        }
        
        return answer;
    }
};