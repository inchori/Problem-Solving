#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N, M;
int ans = INT_MAX;
int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    int left = 0, right = 0;
    while (left < N && right < N) {
        if (abs(arr[right] - arr[left]) >= M) {
            ans = min(ans, abs(arr[left] - arr[right]));
            if (right < N) left++;
        }
        else {
            if (left < N) right++;
        }
    }
    cout << ans << "\n";
    return 0;
}