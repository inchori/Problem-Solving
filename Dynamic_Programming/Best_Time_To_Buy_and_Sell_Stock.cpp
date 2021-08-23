class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp1(prices.size(), 0);
        vector<int> dp2(prices.size(), 0);
        
        dp1[0] = prices[0];
        dp2[prices.size() - 1] = prices[prices.size() - 1];
        
        for (int i = 1; i < prices.size(); i++) {
            dp1[i] = min(dp1[i - 1], prices[i]);
        }
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            dp2[i] = max(dp2[i + 1], prices[i]);
        }
        
        for (int i = 0; i < prices.size(); i++) {
            prices[i] = abs(dp1[i] - dp2[i]);
        }
        
        return *max_element(prices.begin(), prices.end());
    }
};