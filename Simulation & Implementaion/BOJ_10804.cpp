#include <iostream>
#include <algorithm>

using namespace std;

int arr[25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    int i = 0;
    while (i < 10) {
        int a, b;
        cin >> a >> b;
        reverse(arr + a, arr + b + 1);
        i++;
    }

    for (int k = 1; k <= 20; k++) {
        cout << arr[k] << " ";
    }
    return 0;
}