#include <iostream>

using namespace std;

int sudoku[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];

void dfs(int cnt) {
    int x = cnt / 9;
    int y = cnt % 9;

    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    if (sudoku[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                sudoku[x][y] = i;
                dfs(cnt + 1);
                sudoku[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else dfs(cnt + 1);
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] != 0) {
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
            }
        }
    }

    dfs(0);

    return 0;
}