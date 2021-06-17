#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int arr[105][105];
int dist[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INT_MAX;
        }
    }
}

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    dist[x][y] = 0;

    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (arr[nx][ny] == 0) {
                    if (dist[nx][ny] > dist[nowX][nowY]) {
                        dist[nx][ny] = dist[nowX][nowY];
                        q.push(make_pair(nx, ny));
                    }
                } else if (arr[nx][ny] == 1) {
                    if (dist[nx][ny] > dist[nowX][nowY] + 1) {
                        dist[nx][ny] = dist[nowX][nowY] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    init();
    bfs(0, 0);

    printf("%d\n", dist[M - 1][N - 1]);
    return 0;
}