#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int M, N;
bool prime[1000005];
vector<int> V;

void isPrime(int N) {
    prime[0] = prime[1] = true;
    for (int i = 2; i <= sqrt(N); i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);
    isPrime(N);

    for (int i = M; i <= N; i++) {
        if (!prime[i]) V.push_back(i);
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < V.size(); i++) {
        printf("%d\n", V[i]);
    }
    return 0;
}