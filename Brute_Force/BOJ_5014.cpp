#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000005];
queue<int> q;

void bfs() {
    q.push(S);
    visited[S] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == G) {
            return;
        }

        if (now + U >= 1 && now + U <= F && !visited[now + U]) {
            visited[now + U] = visited[now] + 1;
            q.push(now + U);
        }

        if (now - D >= 1 && now - D <= F && !visited[now -D]) {
            visited[now - D] = visited[now] + 1;
            q.push(now - D);
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    bfs();
    if (visited[G] == 0) printf("use the stairs\n");
    else printf("%d\n", visited[G] - 1);
    return 0;
}