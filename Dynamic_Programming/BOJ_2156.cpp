#include <iostream>
#include <algorithm>

using namespace std;

int N;
int wine[10005];
int dp[10005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &wine[i]);
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(wine[0] + wine[2], max(dp[1], wine[1] + wine[2]));

    for (int i = 3; i < N; i++) {
        dp[i] = max(max(dp[i - 2] + wine[i], dp[i - 1]), wine[i] + wine[i - 1] + dp[i - 3]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}