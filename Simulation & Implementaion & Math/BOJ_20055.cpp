#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<int> belt;
deque<bool> visited;

void rotate() {
    visited.push_front(visited.back());
    visited.pop_back();

    belt.push_front(belt.back());
    belt.pop_back();
    visited[N - 1] = false;
}

void move() {
    for (int i = N - 2; i >= 0; i--) {
        if ((!visited[i + 1]) && (belt[i + 1] > 0) && (visited[i])) {
            visited[i] = false;
            visited[i + 1] = true;
            belt[i + 1]--;
        }
    }
    visited[N - 1] = false;
}

void putRobot() {
    if (!visited[0] && belt[0] > 0) {
        visited[0] = true;
        belt[0]--;
    }
}

int checkZero() {
    int zeroCnt = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (belt[i] == 0) zeroCnt++;
    }
    return zeroCnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    int size = 2 * N;
    for (int i = 0; i < size; i++) {
        int dur;
        cin >> dur;
        belt.push_back(dur);
        visited.push_back(false);
    }

    int nowLevel = 1;
    while (true) {
        rotate();
        move();
        putRobot();

        if (checkZero() >= K) break;
        nowLevel++;
    }

    cout << nowLevel << "\n";
    return 0;
}