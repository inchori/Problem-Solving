#include <iostream>

using namespace std;

int N;
int dp[100005];
int pre[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                pre[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                pre[i] = i / 3;
            }
        }
    }

    cout << dp[N] << "\n";
    cout << N << " ";
    while (N - 1) {
        cout << pre[N] << " ";
        if (N == 1) break;
        N = pre[N];
    }
    return 0;
}