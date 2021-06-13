#include <iostream>
#include <queue>
#include <map>

using namespace std;

queue<int> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
map<int, int> visited;

void bfs(int start) {
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int now = q.front();
        string cur = to_string(now);
        q.pop();

        if (now == 123456789) {
            break;
        }

        int z = cur.find('9');
        int x = z / 3;
        int y = z % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string temp = cur;
                swap(temp[x * 3 + y], temp[nx * 3 + ny]);
                int next = stoi(temp);
                if (!visited.count(next)) {
                    visited[next] = visited[now] + 1;
                    q.push(next);
                }
            }
        }

    }
}

int main() {
    int start = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            scanf("%d", &num);
            if (num == 0) num = 9;
            start = start * 10 + num;
        }
    }

    bfs(start);
    if (!visited.count(123456789)) printf("-1\n");
    else printf("%d\n", visited[123456789]);
    return 0;
}