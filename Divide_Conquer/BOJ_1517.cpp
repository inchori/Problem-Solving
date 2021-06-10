#include <iostream>

using namespace std;

typedef long long ll;
int N;
ll arr[500005];
ll temp[500005];
ll result = 0;

void Merge(int left, int mid, int right) {
    int lcnt = left, rcnt = mid + 1;
    int i = left;
    while (lcnt <= mid && rcnt <= right) {
        if (arr[lcnt] <= arr[rcnt]) {
            temp[i++] = arr[lcnt++];
        } else {
            temp[i++] = arr[rcnt++];
            result += (mid + 1 - lcnt);
        }
    }

    while (lcnt <= mid) temp[i++] = arr[lcnt++];
    while (rcnt <= right) temp[i++] = arr[rcnt++];

    for (int j = left; j <= right; j++) {
        arr[j] = temp[j];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (N == 1) {
        printf("0\n");
        return 0;
    }

    mergeSort(0, N - 1);

    printf("%lld\n", result);
    return 0;
}