#include <iostream>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;

    string temp = "";
    int result = 0;
    bool minus = false;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (minus) result -= stoi(temp);
            else result += stoi(temp);
            temp = "";
            if (s[i] == '-') minus = true;
            continue;
        }
        temp += s[i];
    }
    cout << result;
    return 0;
}