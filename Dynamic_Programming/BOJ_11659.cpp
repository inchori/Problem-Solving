#include <iostream>

using namespace std;

int N, M;
int arr[1005];
int dp[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = arr[i] + dp[i - 1];
    }

    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << "\n";
    }
    return 0;
}