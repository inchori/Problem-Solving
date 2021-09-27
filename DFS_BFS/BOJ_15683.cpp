#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, M,  answer = INT_MAX;
int office[10][10];
int copyOffice[10][10];
bool visited[10][10][4];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> v;
vector<int> angle;

void copy() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            copyOffice[i][j] = office[i][j];
        }
    }
}

int getBlind() {
    int zeroCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copyOffice[i][j] == 0) zeroCnt++;
        }
    }
    return zeroCnt;
}

void dfs(int cnt) {
    if (cnt == v.size()) {
        for (int i = 0; i < angle.size(); i++) {
            int x = v[i].first;
            int y = v[i].second;

            for (int j = 0; j < 4; j++) {
                if (visited[x][y][j]) {
                    int nx = x + dx[(angle[i] + j) % 4];
                    int ny = y + dy[(angle[i] + j) % 4];

                    while (true) {
                        if (copyOffice[nx][ny] == 6) break;

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (copyOffice[nx][ny] == 0) {
                                copyOffice[nx][ny] = -1;
                            }

                            nx += dx[(angle[i] + j) % 4];
                            ny += dy[(angle[i] + j) % 4];
                        } else break;
                    }
                }
            }
        }
        answer = min(answer, getBlind());
        copy();
        return;
    }

    for (int i = 0; i < 4; i++) {
        angle.push_back(i);
        dfs(cnt + 1);
        angle.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                v.push_back(make_pair(i, j));
            }

            if (office[i][j] == 1) visited[i][j][0] = true;
            else if (office[i][j] == 2) {
                visited[i][j][0] = true;
                visited[i][j][2] = true;
            }
            else if (office[i][j] == 3) {
                visited[i][j][0] = true;
                visited[i][j][1] = true;
            }
            else if (office[i][j] == 4) {
                visited[i][j][0] = true;
                visited[i][j][1] = true;
                visited[i][j][2] = true;
            }
            else if (office[i][j] == 5) {
                visited[i][j][0] = true;
                visited[i][j][1] = true;
                visited[i][j][2] = true;
                visited[i][j][3] = true;
            }
        }
    }

    copy();
    dfs(0);
    cout << answer << "\n";
    return 0;
}