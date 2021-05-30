#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[305];
int dp[305];


int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0] + arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for (int i = 3; i < N; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }

    printf("%d\n", dp[N - 1]);
    return 0;
}