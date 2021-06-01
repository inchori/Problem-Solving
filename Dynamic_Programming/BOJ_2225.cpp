#include <iostream>
#define MOD 1000000000

using namespace std;

int N, K;
int dp[205][205];

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= N; i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
            }
        }
    }

    printf("%d\n", dp[K][N]);
    return 0;
}