#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[30][30];
bool visited[30][30];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int num = 0;
int cnt = 0;
vector<int> answer;

int dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
            if (arr[nx][ny] == 1) {
                num++;
                dfs(nx, ny);
            }
        }
    }
    return num;
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                answer.push_back(dfs(i, j) + 1);
                num = 0;
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}