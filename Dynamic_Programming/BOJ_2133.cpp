#include <iostream>

using namespace std;

int N;
int dp[35];

int main() {
    scanf("%d", &N);

    if (N % 2 == 1) {
        printf("0\n");
        return 0;
    }

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= N; i+=2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j+=2) {
            dp[i] += dp[i - j] * 2;
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}