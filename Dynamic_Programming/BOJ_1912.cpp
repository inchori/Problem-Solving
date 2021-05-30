#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = -1001, sum = 0;
int arr[100005];
int dp[100005];


int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    dp[0] = arr[0];

    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}