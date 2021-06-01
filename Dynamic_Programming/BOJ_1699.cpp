#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100005];

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}