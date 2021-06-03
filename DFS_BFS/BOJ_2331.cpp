#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int A, P;
int visited[300005];
int ans = 0;

int getNum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += pow(num % 10, P);
        num /= 10;
    }
    return sum;
}

void dfs(int A) {
    visited[A]++;
    if (visited[A] == 3) return;
    dfs(getNum(A));
}

int main() {
    scanf("%d %d", &A, &P);
    dfs(A);
    for (int i = 1; i < 300005; i++) {
        if (visited[i] == 1) ans++;
    }

    printf("%d\n", ans);
    return 0;
}