#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
string arr[105];
bool visited[105][105];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int white = 1, blue = 1;
int whiteSum, blueSum;

int dfsWhite(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
            if (arr[nx][ny] == 'W') {
                white++;
                dfsWhite(nx, ny);
            }
        }
    }
    return white;
}

int dfsBlue(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
            if (arr[nx][ny] == 'B') {
                blue++;
                dfsBlue(nx, ny);
            }
        }
    }
    return blue;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'W' && !visited[i][j]) {
                whiteSum += pow(dfsWhite(i, j), 2);
                white = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'B' && !visited[i][j]) {
                blueSum += pow(dfsBlue(i, j), 2);
                blue = 1;
            }
        }
    }

    printf("%d %d\n", whiteSum, blueSum);
    return 0;
}