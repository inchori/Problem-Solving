#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
vector<string> v;
unordered_map<string, int> u;

bool cmp(string &a, string &b) {
    if (a.length() < b.length()) return a.length() < b.length();
    else {
        if (a.length() == b.length()) return a < b;
        else return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (u[s] >= 1) continue;
        else {
            u[s] += 1;
            v.push_back(s);
        }
    }

    sort(v.begin(), v.end(), cmp);
    for (auto s : v) cout << s << "\n";
    return 0;
}