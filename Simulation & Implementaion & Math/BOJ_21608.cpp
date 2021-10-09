#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
int arr[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
unordered_map<int, vector<int>> u;

struct Coord {
    int x;
    int y;
};

bool containFriends(vector<int> friendList, int adjacentStudnet) {
    for (int i = 0; i < 4; i++) {
        if (friendList[i] == adjacentStudnet) {
            return true;
        }
    }
    return false;
}

void placeStudent(int student) {
    int likeFriendCnt = 0;
    int adjacentEmptyCnt = 0;
    Coord coord = {400 + 40, 400 + 40};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) {
                continue;
            }

            int tempLikeFriendCnt = 0;
            int tempAdjacentEmptyCnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                int adjacentStudent = arr[nx][ny];

                if (adjacentStudent == 0) {
                    tempAdjacentEmptyCnt++;
                    continue;
                }

                if (containFriends(u[student], adjacentStudent)) {
                    tempLikeFriendCnt++;
                }

            }

            if (tempLikeFriendCnt > likeFriendCnt) {
                likeFriendCnt = tempLikeFriendCnt;
                adjacentEmptyCnt = tempAdjacentEmptyCnt;
                coord = {i, j};
                continue;
            }

            if (tempLikeFriendCnt == likeFriendCnt) {
                if (tempAdjacentEmptyCnt > adjacentEmptyCnt) {
                    adjacentEmptyCnt = tempAdjacentEmptyCnt;
                    coord = {i, j};
                    continue;
                }

                if (adjacentEmptyCnt == tempAdjacentEmptyCnt) {
                    if (coord.x > i || (coord.x == i && coord.y > j)) {
                        coord = {i, j};
                    }
                }
            }

        }
    }
    arr[coord.x][coord.y] = student;
}

int makeResult() {
    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int student = arr[i][j];
            vector<int> friends = u[student];
            int likeFriendCnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                int adjacentFriend = arr[nx][ny];

                for (int i = 0; i < friends.size(); i++) {
                    if (friends[i] == adjacentFriend) {
                        likeFriendCnt++;
                        break;
                    }
                }
            }

            if (likeFriendCnt == 0) answer += 0;
            else if (likeFriendCnt == 1) answer += 1;
            else if (likeFriendCnt == 2) answer += 10;
            else if (likeFriendCnt == 3) answer += 100;
            else if (likeFriendCnt == 4) answer += 1000;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int size = N * N;

    vector<int> students(size);

    for (int i = 0; i < size; i++) {
        cin >> students[i];
        vector<int> friends(4);

        for (int j = 0; j < 4; j++) {
            cin >> friends[j];
        }
        u[students[i]] = friends;
    }

    for (int i = 0; i < size; i++) {
        placeStudent(students[i]);
    }

    cout << makeResult() << "\n";
    return 0;
}