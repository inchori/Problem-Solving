#include <iostream>

using namespace std;

int n, ans;

int go(int num) {
    int sum = num;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (go(i) == n) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}