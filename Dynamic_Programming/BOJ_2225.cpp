#include <iostream>
#define MOD 1000000000

using namespace std;

int N, K;
int dp[205][205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    cout << dp[K][N] << "\n";
    return 0;
}