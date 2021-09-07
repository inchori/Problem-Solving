#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[15], op[4];
int minAns = INT_MAX, maxAns = INT_MIN;

void dfs(int depth, int plus, int minus, int multiple, int divide, int ans) {
    if (depth == N) {
        minAns = min(minAns, ans);
        maxAns = max(maxAns, ans);
        return;
    }
    if (plus > 0) dfs(depth + 1, plus - 1, minus, multiple, divide, ans + arr[depth]);
    if (minus > 0) dfs(depth + 1, plus, minus - 1, multiple, divide, ans - arr[depth]);
    if (multiple > 0) dfs(depth + 1, plus, minus, multiple - 1, divide, ans * arr[depth]);
    if (divide > 0) dfs(depth + 1, plus, minus, multiple, divide - 1, ans / arr[depth]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(1, op[0], op[1], op[2], op[3], arr[0]);

    cout << maxAns << "\n";
    cout << minAns << "\n";
    return 0;
}