#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int K;
bool visited[10];
deque<char> wheel[4];

void rotate(int n, int d) {
    visited[n] = true;

    if (n - 1 >= 0 && !visited[n - 1]) {
        if (wheel[n][6] != wheel[n - 1][2]) {
            rotate(n - 1, -d);
        }
    }

    if (n + 1 < 4 && !visited[n + 1]) {
        if (wheel[n][2] != wheel[n + 1][6]) {
            rotate(n + 1, -d);
        }
    }

    if (d == 1) {
        wheel[n].push_front(wheel[n].back());
        wheel[n].pop_back();
    }

    if (d == -1) {
        wheel[n].push_back(wheel[n].front());
        wheel[n].pop_front();
    }

    visited[n] = false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        wheel[i].resize(8);
        for (int j = 0; j < 8; j++) {
            cin >> wheel[i][j];
        }
    }

    cin >> K;

    while (K--) {
        int num, dir;
        cin >> num >> dir;
        rotate(num - 1, dir);
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0] == '1') {
            ans += pow(2, i);
        }
    }

    cout << ans << "\n";
    return 0;
}