#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1005];
int dp1[1005];
int dp2[1005];
int sum[1005];
int ans = 0;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    dp1[0] = 1;
    dp2[N - 1] = 1;

    for (int i = 1; i < N; i++) {
        dp1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        dp2[i] = 1;
        for (int j = N - 1; j > i; j--) {
            if (A[i] > A[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        sum[i] = dp1[i] + dp2[i];
        ans = max(ans, sum[i]);
    }

    printf("%d\n", ans - 1);
    return 0;
}