#include <iostream>
#include <cmath>

using namespace std;

int N, answer = 0;
int arr[505][505];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

double sandPercentage[5][5] = {
        {0, 0, 0.02, 0, 0},
        {0, 0.1, 0.07, 0.01, 0},
        {0.05, 0.45, 0, 0, 0},
        {0, 0.1, 0.07, 0.01, 0},
        {0, 0, 0.02, 0, 0}
};

void rotateSandPercentage() {
    double tempSandPercentage[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tempSandPercentage[i][j] = sandPercentage[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sandPercentage[5 - (j + 1)][i] = tempSandPercentage[i][j];
        }
    }
}

void moveSand(int x, int y) {
    int nowSand = arr[x][y];
    arr[x][y] = 0;

    if (nowSand == 0) return;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            double percentage = sandPercentage[i + 2][j + 2];
            if (percentage == 0) continue;

            int movedSand;

            if (percentage < 0.40) {
                movedSand = floor(nowSand * percentage);
            } else {
                movedSand = nowSand
                        - floor(nowSand * 0.01) * 2
                        - floor(nowSand * 0.02) * 2
                        - floor(nowSand * 0.07) * 2
                        - floor(nowSand * 0.1) * 2
                        - floor(nowSand * 0.05);
            }

            int nx = x + i;
            int ny = y + j;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                answer += movedSand;
                continue;
            }

            arr[nx][ny] += movedSand;
        }
    }
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

    int x = N / 2, y = N / 2;
    int cnt = 1, dir = 0;

    while (true) {
        if (x == 0 && y == 0) break;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < cnt; j++) {
                x = x + dx[dir];
                y = y + dy[dir];

                moveSand(x, y);
                if (x == 0 && y == 0) {
                    cout << answer << "\n";
                    return 0;
                }
            }

            dir = (dir == 3) ? 0 : dir + 1;
            rotateSandPercentage();
        }

        cnt++;
    }

    return 0;
}