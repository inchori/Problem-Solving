#include <iostream>
#define MOD 10007

using namespace std;

int N, ans = 0;
int dp[1005][15];

int main() {
    scanf("%d", &N);

    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            int sum = 0;
            for (int k = j; k <= 9; k++) sum = (sum + dp[i - 1][k]) % MOD;
            dp[i][j] = sum;
        }
    }

    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }

    printf("%d\n", ans);
    return 0;
}