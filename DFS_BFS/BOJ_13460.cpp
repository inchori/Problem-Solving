#include <iostream>
#include <queue>

using namespace std;

struct INFO {
    int rx, ry, bx, by, cnt;
};

int N, M;
char arr[15][15];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
INFO start;
bool visited[15][15][15][15];

int bfs() {
    queue<INFO> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = true;

    int ans = -1;

    while (!q.empty()) {
        INFO now = q.front();
        q.pop();

        if (now.cnt > 10) break;
        if (arr[now.rx][now.ry] == 'O' && arr[now.bx][now.by] != 'O') {
            ans = now.cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nextRx = now.rx;
            int nextRy = now.ry;
            int nextBx = now.bx;
            int nextBy = now.by;

            while (true) {
                if (arr[nextRx][nextRy] != '#' && arr[nextRx][nextRy] != 'O') {
                    nextRx += dx[i];
                    nextRy += dy[i];
                } else {
                    if (arr[nextRx][nextRy] == '#') {
                        nextRx -= dx[i];
                        nextRy -= dy[i];
                    }
                    break;
                }
            }

            while (true) {
                if (arr[nextBx][nextBy] != '#' && arr[nextBx][nextBy] != 'O') {
                    nextBx += dx[i];
                    nextBy += dy[i];
                } else {
                    if (arr[nextBx][nextBy] == '#') {
                        nextBx -= dx[i];
                        nextBy -= dy[i];
                    }
                    break;
                }
            }

            if (nextRx == nextBx && nextRy == nextBy) {
                if (arr[nextRx][nextRy] != 'O') {
                    int redDist = abs(nextRy - now.ry) + abs(nextRx - now.rx);
                    int blueDist = abs(nextBy - now.by) + abs(nextBx - now.bx);

                    if (redDist > blueDist) {
                        nextRx -= dx[i];
                        nextRy -= dy[i];
                    } else {
                        nextBx -= dx[i];
                        nextBy -= dy[i];
                    }
                }
            }

            if (!visited[nextRx][nextRy][nextBx][nextBy]) {
                visited[nextRx][nextRy][nextBx][nextBy] = true;
                INFO next;
                next.rx = nextRx;
                next.ry = nextRy;
                next.bx = nextBx;
                next.by = nextBy;
                next.cnt = now.cnt + 1;
                q.push(next);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') {
                start.rx = i;
                start.ry = j;
            }
            if (arr[i][j] == 'B') {
                start.bx = i;
                start.by = j;
            }
        }
    }

    start.cnt = 0;
    cout << bfs() << "\n";
    return 0;
}