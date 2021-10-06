#include <iostream>
#include <algorithm>

using namespace std;

int N, answer[2];
int arr[15][15];
bool visited1[20];
bool visited2[20];

void backtrack(int x, int y, int cnt, int color) {
    if (x >= N) {
        y++;
        if (x % 2 == 0) x = 1;
        else x = 0;
    }

    if (y >= N) {
        answer[color] = max(answer[color], cnt);
        return;
    }

    if (arr[y][x] && !visited1[x - y + N - 1] && !visited2[x + y]) {
        visited1[x - y + N - 1] = true;
        visited2[x + y] = true;
        backtrack(x + 2, y, cnt + 1, color);
        visited1[x - y + N - 1] = false;
        visited2[x + y] = false;
    }
    backtrack(x + 2, y, cnt, color);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    backtrack(0, 0, 0, 0);
    backtrack(1, 0, 0, 1);

    cout << answer[0] + answer[1];
    return 0;
}