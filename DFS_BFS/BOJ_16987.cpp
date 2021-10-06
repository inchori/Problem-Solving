#include <iostream>
#include <vector>

using namespace std;

int N, cnt, ans = 0;
int s[10], w[10];

void backtrack(int cur) {
    if (cur == N) {
        ans = max(ans, cnt);
        return;
    }
    if (s[cur] <= 0 || cnt == N - 1) {
        backtrack(cur + 1);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (i == cur || s[i] <= 0) continue;
        s[cur] -= w[i];
        s[i] -= w[cur];
        if (s[cur] <= 0) cnt++;
        if (s[i] <= 0) cnt++;
        backtrack(cur + 1);
        if (s[cur] <= 0) cnt--;
        if (s[i] <= 0) cnt--;
        s[cur] += w[i];
        s[i] += w[cur];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> w[i];
    }

    backtrack(0);

    cout << ans << "\n";
    return 0;
}