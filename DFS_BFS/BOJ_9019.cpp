#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
bool visited[10000];

string bfs(int a, int b) {
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = 1;
    while (!q.empty()) {
        int now = q.front().first;
        string nowA = q.front().second;
        q.pop();

        if (now == b) {
            return nowA;
        }

        int next = (2 * now) % 10000;
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, nowA + "D"));
        }
        next = (now - 1) < 0 ? 9999 : now - 1;
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, nowA + "S"));
        }
        next = (now % 1000) * 10 + (now / 1000);
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, nowA + "L"));
        }
        next = (now % 10) * 1000 + (now / 10);
        if (!visited[next]) {
            visited[next] = true;
            q.push(make_pair(next, nowA + "R"));
        }

    }

}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(visited, 0, sizeof(visited));
        int a, b;
        scanf("%d %d", &a, &b);
        cout << bfs(a, b) << "\n";
    }
    return 0;
}