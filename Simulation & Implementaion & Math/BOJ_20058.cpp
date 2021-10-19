#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, Q, MAX = 0, cnt;
int arr[70][70];
bool visited[70][70];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int iceCount() {
    int iceSum = 0;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            iceSum += arr[i][j];
        }
    }
    return iceSum;
}

void countComponent(int x, int y) {
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= (1 << N) || ny < 0 || ny >= (1 << N)) continue;
        if (visited[nx][ny] || arr[nx][ny] == 0) continue;

        countComponent(nx, ny);
    }
}

void rotateArray(int x, int y, int L) {
    int temp[70][70];

    for (int i = x; i < x + (1 << L); i++) {
        for (int j = y; j < y + (1 << L); j++) {
            temp[i][j] = arr[i][j];
        }
    }

    for (int i = x; i < x + (1 << L); i++) {
        for (int j = y; j < y + (1 << L); j++) {
            arr[j - y + x][x + (1 << L) - (i + 1) + y] = temp[i][j];
        }
    }
}

void fireStorm() {
    queue<pair<int, int>> q;

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            if (arr[i][j] == 0) continue;

            int adjCnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= (1 << N) || ny < 0 || ny >= (1 << N)) continue;

                if (arr[nx][ny]) adjCnt++;
            }

            if (adjCnt < 3) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        arr[x][y]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            cin >> arr[i][j];
        }
    }

    int L;
    for (int i = 0; i < Q; i++) {
        cin >> L;

        for (int x = 0; x < (1 << N); x += (1 << L)) {
            for (int y = 0; y < (1 << N); y += (1 << L)) {
                rotateArray(x, y, L);
            }
        }

        fireStorm();
    }

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            if (!visited[i][j] && arr[i][j] > 0) {
                cnt = 0;
                countComponent(i, j);
                MAX = max(MAX, cnt);
            }
        }
    }

    cout << iceCount() << "\n";
    cout << MAX << "\n";
    return 0;
}