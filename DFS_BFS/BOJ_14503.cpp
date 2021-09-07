#include <iostream>

using namespace std;

int N, M;
int r, c, d, answer = 0;
int arr[55][55];

int nextX[4] = {-1, 0, 1, 0};
int nextY[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    while (true) {

        if (arr[r][c] == 0) {
            answer++;
            arr[r][c] = 2;
        }

        bool check = false;

        for (int i = 0; i < 4; i++) {
            if (d == 0) d = 3;
            else if (d == 3) d = 2;
            else if (d == 2) d = 1;
            else if (d == 1) d = 0;

            int nr = r + nextX[d];
            int nc = c + nextY[d];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (!arr[nr][nc]) {
                    r = nr;
                    c = nc;
                    check = true;
                    break;
                }
            }
        }

        if (check) continue;

        int tempDir = d - 2;
        if (tempDir == -2) tempDir = 2;
        if (tempDir == -1) tempDir = 3;

        r = r + nextX[tempDir];
        c = c + nextY[tempDir];

        if (arr[r][c] == 1) break;

    }

    cout << answer << "\n";
    return 0;
}