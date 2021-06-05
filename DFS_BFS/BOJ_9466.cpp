#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, N, cnt;
bool visited[100005], done[100005];
int arr[100005];

void dfs(int start) {
    visited[start] = true;
    int next = arr[start];
    if (!visited[next]) dfs(next);
    else if (!done[next]) {
        for (int i = next; i != start; i = arr[i]) {
            cnt++;
        }
        cnt++;
    }
    done[start] = true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(visited));
        cnt = 0;

        scanf("%d", &N);

        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs(i);
        }

        printf("%d\n", N - cnt);
    }
    return 0;
}