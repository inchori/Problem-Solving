#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int N, zeroCnt;
ll ans = 0;
vector<int> pos;
vector<int> neg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > 0) pos.push_back(num);
        else if (num < 0) neg.push_back(num);
        else zeroCnt++;
    }

    sort(neg.begin(), neg.end(), greater<int>());
    sort(pos.begin(), pos.end());

    for (int i = pos.size() - 1; i >= 1; i -= 2) {
        if (pos[i] + pos[i - 1] > pos[i] * pos[i - 1]) ans += pos[i] + pos[i - 1];
        else ans += pos[i] * pos[i - 1];
    }
    if (pos.size() % 2 != 0) ans += pos[0];

    for (int i = neg.size() - 1; i >= 1; i -= 2) {
        ans += neg[i] * neg[i - 1];
        neg.pop_back();
        neg.pop_back();
    }

    if (!neg.empty() && zeroCnt) neg.pop_back();
    else if (!neg.empty() && !zeroCnt) ans += neg[0];
    cout << ans << "\n";
    return 0;
}