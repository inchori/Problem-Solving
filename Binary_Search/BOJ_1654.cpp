#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
int N, K, ans = 0;
ll arr[10005];

int main() {
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }

    long long lo = 1, hi = pow(2, 31) - 1;

    while (lo <= hi) {
        ll temp = 0;
        ll mid = (lo + hi) / 2;
        for (int i = 0; i < K; i++) {
            temp += arr[i] / mid;
        }

        if (temp < N) {
            hi = mid - 1;
        } else {
            ans = mid;
            lo = mid + 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}