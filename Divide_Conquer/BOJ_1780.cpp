#include <iostream>

using namespace std;

int N;
int paper[2200][2200];
int answer[3];
bool minusone, zero, one;

bool same(int x, int y, int N) {
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (paper[x][y] != paper[i][j]) return false;
        }
    }
    return true;
}

void go(int x, int y, int N) {

    if (same(x, y, N)) {
        answer[paper[x][y] + 1]++;
        return;
    }

    int M = N / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            go(x + i * M, y + j * M, M);
        }
    }
}


int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    go(0, 0, N);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}