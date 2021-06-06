#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll N, M, hi, ans;
ll arr[1000005];


int main() {

    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
        hi = max(hi, arr[i]);
    }

    int lo = 1;

    while (lo <= hi) {
        ll temp = 0;
        ll mid = (lo + hi) / 2;
        for (int i = 0; i < N; i++) {
            if (arr[i] < mid) continue;
            temp += arr[i] - mid;
        }

        if (temp >= M) {
            lo = mid + 1;
            ans = mid;
        } else if (temp < M) {
            hi = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}