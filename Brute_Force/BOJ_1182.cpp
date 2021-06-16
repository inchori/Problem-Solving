#include <iostream>

using namespace std;

int N, S, result;
int arr[25];

void go(int i, int sum) {
    if (i == N) return;
    if (sum + arr[i] == S) result++;

    go(i + 1, sum + arr[i]);
    go(i + 1, sum);
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    go(0, 0);

    printf("%d\n", result);
    return 0;
}