#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isRight(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (!st.empty()) {
                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
            } else st.push(s[i]);
        }
    }
    
    if (st.empty()) return true;
    else return false;
}

string rotate(string str) {
    string res = str;
    char tmp = res[0];
    res.erase(0, 1);
    res += tmp;
    return res;
}

int solution(string s) {
    int answer = 0;
    if (s.length() % 2 != 0) return 0;
    if (isRight(s)) answer++;
    for (int i = 1; i < s.length(); i++) {
        s = rotate(s);
        if (isRight(s)) answer++;
    }
    return answer;
}