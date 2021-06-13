#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, A, B;
bool visited[10000];
string answer = "";

void bfs(int start, int end) {
    queue<pair<int, string>> q;
    q.push(make_pair(start, ""));
    visited[start] = true;

    while (!q.empty()) {
        int now = q.front().first;
        string DSLR = q.front().second;
        q.pop();

        if (now == end) {
            answer = DSLR;
            return;
        }

        int cur;
        now * 2 > 9999 ? cur = (now * 2) % 10000 : cur = now * 2;
        if (!visited[cur]) {
            visited[cur] = true;
            q.push(make_pair(cur, DSLR + "D"));
        }

        now - 1 < 0 ? cur = 9999 : cur = now - 1;
        if (!visited[cur]) {
            visited[cur] = true;
            q.push(make_pair(cur, DSLR + "S"));
        }

        cur = (now / 1000) + (now % 1000) * 10;
        if (!visited[cur]) {
            visited[cur] = true;
            q.push(make_pair(cur, DSLR + "L"));
        }

        cur = (now / 10) + (now % 10) * 1000;
        if (!visited[cur]) {
            visited[cur] = true;
            q.push(make_pair(cur, DSLR + "R"));
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(visited, false, sizeof(visited));
        scanf("%d %d", &A, &B);
        bfs(A, B);
        cout << answer << "\n";
    }
    return 0;
}