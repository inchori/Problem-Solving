#include <iostream>

using namespace std;

int N, M, K, X = 1;
int ans = 0;

int main() {
    scanf("%d %d %d", &N, &M, &K);
    int total = N + M - K;

    while (true) {
        int tempN = 2 * X;
        int tempM = X;
        if (tempN + tempM > total || tempN > N || tempM > M) break;
        X++;
    }

    printf("%d\n", --X);
    return 0;
}