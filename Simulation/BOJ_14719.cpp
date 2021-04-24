#include <iostream>
#include <algorithm>

using namespace std;

int h, w;
int arr[505];
int ans;

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < w; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < w; i++) {
        int left = 0, right = 0;
        for (int j = 0; j < i; j++) left = max(left, arr[j]);
        for (int j = w - 1; j > i; j--) right = max(right, arr[j]);
        ans += max(0, min(left, right) - arr[i]);
    }

    printf("%d\n", ans);
    return 0;
}