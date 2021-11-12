class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        vector<int> temp;
        for (auto iter = s.begin(); iter != s.end(); iter++) temp.push_back(*iter);
        
        sort(temp.begin(), temp.end());
        int left = 0, right = 1;
        int answer = 1;
        int cnt = 1;
        while (left < temp.size() && right < temp.size()) {
            if (temp[right] - temp[left] == cnt) {
                answer = max(answer, right - left + 1);
                right++;
                cnt++;
            }
            else {
                left = right;
                right = left + 1;
                cnt = 1;
            }
        }
        
        return answer;
    }
};