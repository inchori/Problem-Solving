#include <iostream>
#include <cstring>

using namespace std;

int N, M, K, ans;
string map[105];
int visited[105][105][85];
string standard;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int x, int y, int idx) {
    if (visited[x][y][idx] != -1) return visited[x][y][idx];

    if (idx == standard.length()) {
        visited[x][y][idx] = 1;
        return 1;
    }

    visited[x][y][idx] = 0;

    for (int i = 0; i < 4; i++) {

        for (int j = 1; j <= K; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == standard[idx]) {
                    visited[x][y][idx] += dfs(nx, ny, idx + 1);
                }

            }
        }

    }
    return visited[x][y][idx];
}

int main() {
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    cin >> standard;

    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == standard[0]) {
                ans += dfs(i, j, 1);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}