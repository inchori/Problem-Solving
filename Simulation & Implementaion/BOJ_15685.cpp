#include <iostream>
#include <vector>

using namespace std;

int N, ans = 0;
int x, y, d, g;
int arr[105][105];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<int> dir;

void makeCurve() {
//    int T = (1 << g) - 1;

    int S = dir.size();
    for (int i = S - 1; i >= 0; i-- ) {
        int nd = (dir[i] + 1) % 4;
        x = x + dx[nd];
        y = y + dy[nd];
        arr[y][x] = 1;
        dir.push_back(nd);
    }
}

void countSquare() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
                ans++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    while (N--) {
        cin >> x >> y >> d >> g;
        dir.clear();
        arr[y][x] = 1;
        y += dy[d];
        x += dx[d];
        arr[y][x] = 1;
        dir.push_back(d);
        while (g--) {
            makeCurve();
        }
    }

    countSquare();
    cout << ans << "\n";
    return 0;
}