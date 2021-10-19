#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int N, L, R, population, num;
int city[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool visited[55][55];
int answer = 0;
vector<pair<int, int>> v;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (abs(city[x][y] - city[nx][ny]) >= L && abs(city[x][y] - city[nx][ny]) <= R && !visited[nx][ny]) {
                visited[nx][ny] = true;
                v.push_back(make_pair(nx, ny));
                population += city[nx][ny];
                num++;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
        }
    }


    while (true) {
        memset(visited, false, sizeof(visited));

        bool found = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    population = city[i][j];
                    num = 1;

                    v.clear();
                    v.push_back(make_pair(i, j));
                    dfs(i, j);
                }

                if (num >= 2) {
                    found = true;
                    for (int k = 0; k < v.size(); k++) {
                        city[v[k].first][v[k].second] = population / num;
                    }
                }
            }
        }

        if (found) answer++;
        else break;
    }

    cout << answer << "\n";
    return 0;
}