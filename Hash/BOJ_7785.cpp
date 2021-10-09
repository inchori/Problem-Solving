#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;
        if (state == "enter") m[name] += 1;
        else m.erase(name);
    }

    vector<string> answer;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer.push_back(iter->first);
    }
    sort(answer.begin(), answer.end(), greater<string>());

    for (string s : answer) cout << s << "\n";
    return 0;
}