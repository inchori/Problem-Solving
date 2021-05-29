#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1005];
int dp[1005];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    dp[N - 1] = 1;

    for (int i = N - 2; i >= 0; i--) {
        dp[i] = 1;
        for (int j = N - 1; j >= i; j--) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}