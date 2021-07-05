#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll N, M, ans = 0;
ll arr[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N ;
    ll lo = 1, hi = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    cin >> M;

    while (lo <= hi) {
        ll sum = 0;
        ll mid = (lo + hi) / 2;
        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) sum += mid;
            else sum += arr[i];
        }

        if (sum <= M) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;

    }

    cout << ans << "\n";
    return 0;
}