#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, sum;
int arr[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    sum += arr[0];

    for (int i = 1; i < N; i++) {
        arr[i] += arr[i - 1];
        sum += arr[i];
    }

    cout << sum << "\n";

    return 0;
}