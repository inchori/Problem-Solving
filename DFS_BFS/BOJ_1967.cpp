#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<vector<pair<int, int>>> G;
bool visited[10005];
int farthest;

void dfs(int start, int cost) {
    if (visited[start]) return;

    visited[start] = true;
    if (ans < cost) {
        ans = cost;
        farthest = start;
    }

    for (int i = 0; i < G[start].size(); i++) {
        int next = G[start][i].first;
        int dist = G[start][i].second;
        dfs(next, cost + dist);
    }
}

int main() {
    scanf("%d", &n);

    G.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        G[from].push_back(make_pair(to, weight));
        G[to].push_back(make_pair(from, weight));
    }

    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    ans = 0;

    dfs(farthest, 0);

    printf("%d\n", ans);
    return 0;
}