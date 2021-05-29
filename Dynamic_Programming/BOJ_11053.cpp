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

    dp[0] = 1;

    for (int i = 1; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
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