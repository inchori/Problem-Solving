#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, W[15][15], ans = INT_MAX;
vector<int> temp;
bool visited[15];

void go(int now, int depth) {
    if (depth == N) {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += W[temp[i]][temp[i + 1]];
        }
        if (W[temp[N - 1]][temp[0]] == 0) return;
        else {
            sum += W[temp[N - 1]][temp[0]];
            ans = min(ans, sum);
            return;
        }
    }

    for (int i = 0; i < N; i++) {
        if (W[now][i] == 0) continue;
        else if (!visited[i]) {
            visited[i] = true;
            temp.push_back(i);
            go(i, depth + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    go(0, 0);

    printf("%d\n", ans);
    return 0;
}