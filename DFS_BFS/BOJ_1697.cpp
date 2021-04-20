#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pp;

int n, k, answer;
bool visited[100005];
queue<pp> q;

void bfs(int start, int end) {
    q.push(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == end) {
            answer = cnt;
            return;
        }

        if (!visited[now - 1] && (now - 1) >= 0) {
            q.push(make_pair(now - 1, cnt + 1));
            visited[now - 1] = true;
        }
        if (!visited[now + 1] && (now + 1) < 100001) {
            q.push(make_pair(now + 1, cnt + 1));
            visited[now + 1] = true;
        }
        if (!visited[now * 2] && (now * 2) < 100001) {
            q.push(make_pair(now * 2, cnt + 1));
            visited[now * 2] = true;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    bfs(n, k);
    printf("%d\n", answer);
    return 0;
}