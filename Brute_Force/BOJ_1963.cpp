#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, A, B;
int visited[10000];
bool prime[10000];

void erathos() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 10000; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                prime[j] = true;
            }
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(A);
    visited[A] = 0;

    while (!q.empty()) {
        int nowNum = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            string node = to_string(nowNum);
            for (int j = 0; j < 10; j++) {
                node[i] = j + '0';
                int next = stoi(node);
                if (next >= 1000 && visited[next] == -1 && !prime[next]) {
                    visited[next] = visited[nowNum] + 1;
                    q.push(next);
                }
            }
        }
    }

}


int main() {
    scanf("%d", &T);
    erathos();


    while (T--) {
        memset(visited, -1, sizeof(visited));
        scanf("%d %d", &A, &B);
        bfs();
        if (visited[B] != -1) printf("%d\n", visited[B]);
        else printf("Impossible\n");
    }

    return 0;
}