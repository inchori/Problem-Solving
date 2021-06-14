#include <iostream>

using namespace std;

int map[2001][2001];
int N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    if (y < 0 || x < 0 || x >= 2001 || y >= 2001) return;
    if (map[x][y] == 2 || map[x][y] == 0) return;

    map[x][y] = 2;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 = (x1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y1 = (y1 + 500) * 2;
        y2 = (y2 + 500) * 2;

        for (int j = x1; j <= x2; j++) {
            map[y1][j] = 1;
            map[y2][j] = 1;
        }

        for (int j = y1; j <= y2; j++) {
            map[j][x1] = 1;
            map[j][x2] = 1;
        }
    }

    int cnt = 0;

    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (map[i][j] == 1) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    if (map[1000][1000] == 2) cnt--;
    cout << cnt << "\n";

    return 0;
}