#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N, L;
int arr[105][105];
bool visited[105];
int rowCnt, colCnt;

void checkRow(int x) {
    int cur = arr[x][0];

    for (int i = 0; i < N; i++) {
        if (arr[x][i] != cur) {
            if (abs(arr[x][i] - cur) > 1) return;

            if (arr[x][i] < cur) {
                int height = -1;

                for (int j = i; j < i + L; j++) {
                    if (!visited[j] && j < N) {
                        visited[j] = true;
                        if (height == -1) {
                            height = arr[x][j];
                            continue;
                        }

                        if (height != -1 && arr[x][j] != height) return;
                    } else return;
                }

                i += L - 1;
                if (i >= N) break;
            } else {
                int height = -1;
                for (int j = i - 1; j > i - 1 - L; j--) {
                    if (!visited[j] && j >= 0) {
                        visited[j] = true;

                        if (height == -1) {
                            height = arr[x][j];
                            continue;
                        }

                        if (height != -1 && arr[x][j] != height) return;
                    }
                    else return;
                }
            }
            cur = arr[x][i];
        }
    }
    rowCnt++;
}

void checkCol(int y) {
    int cur = arr[0][y];

    for (int i = 0; i < N; i++) {
        if (arr[i][y] != cur) {
            if (abs(arr[i][y] - cur) > 1) return;

            if (arr[i][y] < cur) {
                int height = -1;

                for (int j = i; j < i + L; j++) {
                    if (!visited[j] && j < N) {
                        visited[j] = true;
                        if (height == -1) {
                            height = arr[j][y];
                            continue;
                        }

                        if (height != -1 && arr[j][y] != height) return;
                    } else return;
                }

                i += L - 1;
                if (i >= N) break;
            } else {
                int height = -1;
                for (int j = i - 1; j > i - 1 - L; j--) {
                    if (!visited[j] && j >= 0) {
                        visited[j] = true;

                        if (height == -1) {
                            height = arr[j][y];
                            continue;
                        }

                        if (height != -1 && arr[j][y] != height) return;
                    }
                    else return;
                }
            }
            cur = arr[i][y];
        }
    }
    colCnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        checkRow(i);
    }

    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        checkCol(i);
    }


    cout << rowCnt + colCnt << "\n";
    return 0;
}