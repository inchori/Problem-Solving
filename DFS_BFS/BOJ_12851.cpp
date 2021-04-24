#include <iostream>
#include <queue>
#include <map>
#include <climits>

using namespace std;

int n, k;
queue<pair<int, int>> q;
int answer = INT_MAX;
map<int, int> temp;
bool visited[200005];

void bfs(int start, int target) {
    q.push(make_pair(start, 0));
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[now] = true;

        if (now == target) {
            temp[cnt]++;
            answer = min(answer, cnt);
        }

        if ((now - 1) >= 0 && (now - 1) < 100001 && !visited[now - 1]) {
            q.push(make_pair(now - 1, cnt + 1));
        }

        if ((now + 1) < 100001 && (now + 1) >= 0 && !visited[now + 1]) {
            q.push(make_pair(now + 1, cnt + 1));
        }

        if ((now * 2) < 100001 && (now * 2) >= 0 && !visited[now * 2]) {
            q.push(make_pair(now * 2, cnt + 1));
        }

    }
}

int main() {
    scanf("%d %d", &n, &k);
    bfs(n, k);
    printf("%d\n", answer);
    printf("%d\n", temp[answer]);
    return 0;
}