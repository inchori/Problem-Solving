#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j]) {
                board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer * answer;;
}