#include <iostream>
#include <vector>

using namespace std;

int N, cnt = 0;
bool visited[40];
bool visited2[40];
bool visited3[40];

void backtrack(int cur) {
    if (cur == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && !visited2[i + cur] && !visited3[cur - i + N - 1]) {
            visited[i] = true;
            visited2[i + cur] = true;
            visited3[cur - i + N - 1] = true;
            backtrack(cur + 1);
            visited[i] = false;
            visited2[i + cur] = false;
            visited3[cur - i + N - 1] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    backtrack(0);
    cout << cnt << "\n";
    return 0;
}