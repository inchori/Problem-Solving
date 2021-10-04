#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K, cnt, ans;
int arr[105][105];
bool visited[105][105];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> area;

void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (visited[nx][ny] || arr[nx][ny] != 0) continue;

        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        for (int j = M - y2; j < M - x2; j++) {
            for (int k = x1; k < y1; k++) {
                arr[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                area.push_back(cnt);
                ans++;
            }
        }
    }

    sort(area.begin(), area.end());
    cout << ans << "\n";
    for (auto item : area) cout << item << " ";
    return 0;
}