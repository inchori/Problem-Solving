class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        if (s.length() <= 1) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            if (st.empty()) return false;
            else {
                if (s[i] == ')') {
                    if (st.top() == '(') st.pop();
                    else return false;
                }
                if (s[i] == '}') {
                    if (st.top() == '{') st.pop();
                    else return false;
                }
                if (s[i] == ']') {
                    if (st.top() == '[') st.pop();
                    else return false;
                }
            }
        }
        
        if (st.empty()) return true;
        else return false;
    }
};