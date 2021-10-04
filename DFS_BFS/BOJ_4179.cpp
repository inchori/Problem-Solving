#include <iostream>
#include <queue>

using namespace std;

int r, c;
char arr[1005][1005];
int visited1[1005][1005];
int visited2[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> jq;
queue<pair<int, int>> fq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'J') {
                jq.push(make_pair(i, j));
                visited2[i][j] = 1;
            }
            if (arr[i][j] == 'F') {
                fq.push(make_pair(i, j));
                visited1[i][j] = 1;
            }
        }
    }

    while (!fq.empty()) {
        int nowX = fq.front().first;
        int nowY = fq.front().second;

        fq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited1[nx][ny] > 0 || arr[nx][ny] == '#') continue;

            visited1[nx][ny] = visited1[nowX][nowY] + 1;
            fq.push(make_pair(nx, ny));
        }
    }

    while (!jq.empty()) {
        int nowR = jq.front().first;
        int nowC = jq.front().second;
        jq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = nowR + dx[i];
            int nc = nowC + dy[i];

            if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                cout << visited2[nowR][nowC];
                return 0;
            }
            if (visited2[nr][nc] > 0 || arr[nr][nc] == '#') continue;
            if (visited1[nr][nc] != 0 && visited1[nr][nc] <= visited2[nowR][nowC] + 1) continue;

            visited2[nr][nc] = visited2[nowR][nowC] + 1;
            jq.push(make_pair(nr, nc));
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}