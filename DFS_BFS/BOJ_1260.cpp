#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> adj;
queue<int> q;
bool visited[1005];
int n, m, v;

void dfs(int start) {
    visited[start] = true;
    printf("%d ", start);
    for (int i = 0; i < adj[start].size(); i++) {
        int next = adj[start][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        printf("%d ", now);
        q.pop();

        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}


int main() {
    scanf("%d %d %d", &n, &m, &v);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int i = 1; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    printf("\n");
    memset(visited, false, sizeof(visited));
    bfs(v);
    printf("\n");
    return 0;
}