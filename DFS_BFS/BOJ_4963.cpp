#include <iostream>
#include <cstring>

using namespace std;

int w, h, ans;
bool visited[55][55];
int island[55][55];

int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[8] = {-1, 0, 1, 0, -1, 1, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
            if (island[nx][ny] == 1) dfs(nx, ny);
        }
    }
}


int main() {

    while (true) {
        memset(visited, false, sizeof(visited));
        ans = 0;
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &island[i][j]);
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && island[i][j] == 1) {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}