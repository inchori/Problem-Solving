#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }

    sort(v.begin(), v.end());
    for (auto s : v) cout << s << "\n";
    return 0;
}