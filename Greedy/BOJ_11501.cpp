#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int arr[1000005];
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        int mx = -1, N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        ll ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            mx = max(mx, arr[i]);
            ans += mx - arr[i];
        }

        cout << ans << "\n";
    }
    return 0;
}