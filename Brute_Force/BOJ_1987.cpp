#include <iostream>
#include <algorithm>

using namespace std;

int R, C, ans = 0;
string alpha[25];
bool visited[25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int cnt) {

    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if (!visited[alpha[nx][ny] - 'A']) {
                visited[alpha[nx][ny] - 'A'] = true;
                dfs(nx, ny, cnt + 1);
                visited[alpha[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        cin >> alpha[i];
    }

    visited[alpha[0][0] - 'A'] = true;

    dfs(0, 0, 1);


    printf("%d\n", ans);
    return 0;
}