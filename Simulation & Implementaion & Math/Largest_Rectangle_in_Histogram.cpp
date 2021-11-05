class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        
        int answer = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - 1- st.top();
                answer = max(answer, height * width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? heights.size() : heights.size() - 1 - st.top();
            answer = max(answer, height * width);
        }
        return answer;
    }
};