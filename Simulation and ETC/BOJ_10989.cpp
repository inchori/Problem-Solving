#include <iostream>
#include <algorithm>

using namespace std;

int N, k = 0;
int temp;
int cntArr[10001];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        cntArr[temp]++;
        k = max(k, temp);
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < cntArr[i]; j++) printf("%d\n", i);
    }

    return 0;
}