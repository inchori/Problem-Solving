#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
bool prime[1000005];
bool flag;

void isPrime() {
    prime[0] = prime[1] = true;
    for (int i = 2; i <= sqrt(1000000); i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = true;
            }
        }
    }
}

int main() {
    isPrime();
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;

        for (int i = 2; i <= N / 2; i++) {
            if (!prime[i] && !prime[N - i]) {
                printf("%d = %d + %d\n", N, i, N - i);
                flag = true;
                break;
            }
        }

        if (!flag) printf("Goldbach's conjecture is wrong.\n");

    }


    return 0;
}