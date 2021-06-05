#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, ans = 0;
int tomato[1005][1005];
int visited[1005][1005];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }


    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                if (tomato[nx][ny] == 0) {
                    visited[nx][ny] = visited[nowX][nowY] + 1;
                    tomato[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            ans = max(ans, visited[i][j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}