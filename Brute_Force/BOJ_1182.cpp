#include <iostream>

using namespace std;

int N, S, ans = 0;
int arr[25];

void dfs(int sum, int idx) {
    if (idx == N - 1) {
        if (sum == S) {
            ans++;
        }
        return;
    }
    dfs(sum + arr[idx], idx + 1);
    dfs(sum, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);
    if (S == 0) ans -= 1;
    cout << ans << "\n";
    return 0;
}