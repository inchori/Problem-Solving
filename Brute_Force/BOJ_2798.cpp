#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, answer, sum;
int arr[105];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if (sum <= m) {
                    answer = max(answer, sum);
                }
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}