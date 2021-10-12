#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    vector<bool> prime(N + 1, true);
    prime[1] = false;


    int ans = 0, cnt = 0;

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            if (prime[j]) {
                prime[j] = false;
                cnt++;
                if (cnt == K) {
                    cout << j << "\n";
                    return 0;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}