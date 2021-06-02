#include <iostream>
#define MOD 1000000

using namespace std;

int dp[5005];
int arr[5005];
string input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;

    if (input[0] == '0') {
        cout << 0 << "\n";
        return 0;
    }

    int len = input.length();
    dp[0] = 1;


    for (int i = 1; i <= len; i++) {
        arr[i] = input[i - 1] - '0';
    }

    for (int i = 1; i <= len; i++) {
        if (arr[i] >= 1 && arr[i] <= 9) {
            dp[i] = (dp[i - 1] + dp[i]) % MOD;
        }

        if (i == 1) continue;

        int temp = arr[i] + arr[i - 1] * 10;
        if (temp >= 10 && temp <= 26) {
            dp[i] = (dp[i - 2] + dp[i]) % MOD;
        }
    }

    cout << dp[len] << "\n";
    return 0;
}