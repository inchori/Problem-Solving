#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k, cnt = 1, ans = 0;
int arr[105][105];
bool visited[105][105];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
            if (arr[nx][ny] == 1) {
                cnt++;
                dfs(nx, ny);
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        arr[r][c] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                ans = max(ans, dfs(i, j));
                cnt = 1;
                memset(visited, false, sizeof(visited));
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}