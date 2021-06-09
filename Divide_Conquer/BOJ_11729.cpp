#include <iostream>
#include <cmath>

using namespace std;

int n, cnt;

void hanoi(int n, int from, int temp, int to) {
    if (n == 1) {
        printf("%d %d\n", from, to);
        cnt++;
    }
    else {
        hanoi(n - 1, from, to, temp);
        printf("%d %d\n", from, to);
        cnt++;
        hanoi(n - 1, temp, from, to);
    }
}

int main() {
    scanf("%d", &n);
    cnt = pow(2, n) - 1;
    printf("%d\n", cnt);
    hanoi(n, 1, 2, 3);
    return 0;
}