#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int map[105][105];
bool visited[105][105];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int cnt) {
    visited[x][y] = true;
    map[x][y] = cnt;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >=0 && ny < N && !visited[nx][ny]) {
            if (map[nx][ny]) {
                dfs(nx, ny, cnt);
            }
        }
    }
}

int bfs(int cnt) {
    queue<pair<int, int>> q;
    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == cnt) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (map[nx][ny] && map[nx][ny] != cnt) return result;
                    else if (map[nx][ny] == 0 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        result++;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int cnt = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 1; i < cnt; i++) {
        memset(visited, false, sizeof(visited));
        answer = min(answer, bfs(i));
    }

    printf("%d\n", answer);
    return 0;
}