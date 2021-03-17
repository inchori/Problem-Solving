#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int arr[1005][1005];
int visited[1005][1005][15];
int n, m, k, answer = INT_MAX;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int x, int y, int w) {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x, y), w));
    visited[x][y][w] = 1;

    while (!q.empty()) {
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int nowB = q.front().second;
        q.pop();

        if (nowX == n - 1 && nowY == m - 1) {
            answer = min(answer, visited[n - 1][m - 1][nowB]);
        }

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] == 0) {
                    if (visited[nx][ny][nowB] == -1) {
                        visited[nx][ny][nowB] = visited[nowX][nowY][nowB] + 1;
                        q.push(make_pair(make_pair(nx, ny), nowB));
                    }
                }
                else {
                    if (nowB < k) {
                        if (visited[nx][ny][nowB + 1] == -1) {
                            visited[nx][ny][nowB + 1] = visited[nowX][nowY][nowB] + 1;
                            q.push(make_pair(make_pair(nx, ny), nowB + 1));
                        }
                    }
                }
            }
        }
    }

    if (answer == INT_MAX) return -1;
    return answer;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int t = 0; t <= k; t++) {
                visited[i][j][t] = -1;
            }
        }
    }

    printf("%d\n", bfs(0, 0, 0));
    return 0;
}