#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int paper[505][505];
bool visited[505][505];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int answer = 0;

void dfs(int x, int y, int sum, int depth) {
    visited[x][y] = true;

    if (depth == 3) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if (!visited[nx][ny]) {
                dfs(nx, ny, sum + paper[nx][ny], depth + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

//ㅗ
void shape1(int x, int y) {
    int tempSum = 0;
    tempSum = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x - 1][y + 1];
    answer = max(answer, tempSum);
}

//ㅜ
void shape2(int x, int y) {
    int tempSum = 0;
    tempSum = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x + 1][y + 1];
    answer = max(answer, tempSum);
}

//ㅏ
void shape3(int x, int y) {
    int tempSum = 0;
    tempSum = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + 1][y + 1];
    answer = max(answer, tempSum);
}

//ㅓ
void shape4(int x, int y) {
    int tempSum = 0;
    tempSum = paper[x][y] + paper[x - 1][y + 1] + paper[x][y + 1] + paper[x + 1][y + 1];
    answer = max(answer, tempSum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            memset(visited, false, sizeof(visited));
            dfs(i, j, paper[i][j], 0);
            if (i - 1 >= 0 && j + 2 < M) shape1(i, j);
            if (j + 2 < M && i + 1 < N) shape2(i, j);
            if (i + 2 < N && j + 1 < M) shape3(i, j);
            if (i + 1 < N && i - 1 >= 0 && j + 1 < M) shape4(i, j);
        }
    }

    cout << answer << "\n";
    return 0;
}