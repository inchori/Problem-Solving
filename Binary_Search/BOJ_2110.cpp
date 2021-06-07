#include <iostream>
#include <algorithm>

using namespace std;

int N, C, ans;
int house[200005];

int main() {
    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++) {
        scanf("%d", &house[i]);
    }

    sort(house, house + N);
    int lo = 1, hi = house[N - 1] - house[0];

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int cnt = 1;
        int prev = house[0];

        for (int i = 1; i < N; i++) {
            if (house[i] - prev >= mid) {
                cnt++;
                prev = house[i];
            }
        }

        if (cnt >= C) {
            ans = max(ans, mid);
            lo = mid + 1;
        } else hi = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}