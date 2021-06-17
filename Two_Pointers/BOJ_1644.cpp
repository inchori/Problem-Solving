#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, result = 0;
bool prime[4000005];
vector<int> arr;

void isPrime(int N) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i <= sqrt(N); i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    isPrime(N);

    if (N == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (prime[i]) arr.push_back(i);
    }

    if (prime[N]) result++;

    int left = 0, right = 1;
    int sum = arr[0];

    while (left < arr.size() && right < arr.size()) {
        if (sum == N) {
            result++;
            sum -= arr[left];
            left++;
        } else if (sum < N) {
            sum += arr[right];
            right++;
        } else if (sum > N) {
            sum -= arr[left];
            left++;
        }
    }

    printf("%d\n", result);
    return 0;
}