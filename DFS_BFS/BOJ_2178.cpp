#include <iostream>
#include <queue>

using namespace std;

int N, M, ans = 0;
int maze[105][105];
int visited[105][105];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int> > q;

void bfs(int x, int y) {
    visited[x][y] = true;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                if (maze[nx][ny] == 1) {
                    visited[nx][ny] = visited[nowX][nowY] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs(0, 0);

    printf("%d\n", visited[N - 1][M - 1]);
    return 0;
}