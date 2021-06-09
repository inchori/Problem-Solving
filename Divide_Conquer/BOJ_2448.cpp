#include <iostream>
#include <cstring>

using namespace std;

char star[3][6] =
        {"  *  ",
         " * * ",
         "*****"};
char map[3500][6500];
int N;

void go(int x, int y, int N) {
    if (N == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                map[x + i][y + j] = star[i][j];
            }
        }
        return;
    }
    go(x, y + 3 * N / 2, N / 2);
    go(x + 3 * N / 2, y, N / 2);
    go(x + 3 * N / 2, y + 3 * N, N / 2);
}

int main() {
    scanf("%d", &N);
    memset(map, ' ', sizeof(map));
    go(0, 0, N / 3);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}