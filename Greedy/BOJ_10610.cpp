#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

string N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag = false;
    long long sum = 0;

    cin >> N;

    for (int i = 0; i < N.length(); i++) {
        int temp = N[i] - '0';
        if (temp == 0) flag = true;
        sum += temp;
    }

    if (sum % 3 || !flag) cout << -1 << "\n";
    else {
        sort(N.begin(), N.end(), greater<>());
        cout << N << "\n";
    }

    return 0;
}