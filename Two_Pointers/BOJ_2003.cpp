#include <iostream>

using namespace std;

int N, M, ans = 0;
int arr[10005];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = 0;
    int sum = arr[0];

    while (left < N && right < N) {
        if (sum < M) {
            right++;
            sum += arr[right];
        } else if (sum > M) {
            sum -= arr[left];
            left++;
        } else {
            ans++;
            right++;
            sum += arr[right];
        }
    }
    printf("%d\n", ans);
    return 0;
}