#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int allDir[4] = {0, 2, 4, 6};
int notDir[4] = {1, 3, 5, 7};

typedef struct fireBall {
    int x;
    int y;
    int mass;
    int speed;
    int dir;
} fireBall;

vector<fireBall> v;
vector<fireBall> arr[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        v.push_back({r, c, m, s, d});
        arr[r][c].push_back({r, c, m, s, d});
    }

    while (K--) {

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j].clear();
            }
        }

        for (int i = 0; i < v.size(); i++) {
            int nowR = v[i].x;
            int nowC = v[i].y;
            int nowSpeed = v[i].speed;
            int nowMass = v[i].mass;
            int nowDir = v[i].dir;

            int move = nowSpeed % N;
            int nr = nowR + dx[nowDir] * move;
            int nc = nowC + dy[nowDir] * move;
            if (nr > N) nr -= N;
            if (nc > N) nc -= N;
            if (nr < 1) nr += N;
            if (nc < 1) nc += N;
            arr[nr][nc].push_back({nr, nc, nowMass, nowSpeed, nowDir});
            v[i].x = nr;
            v[i].y = nc;
        }

        vector<fireBall> temp;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j].size() == 0) continue;
                if (arr[i][j].size() == 1) {
                    temp.push_back(arr[i][j][0]);
                    continue;
                }

                int massSum = 0;
                int speedSum = 0;
                int cnt = arr[i][j].size();
                bool even = true, odd = true;
                for (int k = 0; k < arr[i][j].size(); k++) {
                    massSum += arr[i][j][k].mass;
                    speedSum += arr[i][j][k].speed;
                    if (arr[i][j][k].dir % 2 == 0) odd = false;
                    else even = false;
                }

                int finalMass = massSum / 5;
                int finalSpeed = speedSum / cnt;
                if (finalMass == 0) continue;

                if (even || odd) {
                    for (int k = 0; k < 4; k++) {
                        temp.push_back({i, j, finalMass, finalSpeed, allDir[k]});
                    }
                } else {
                    for (int k = 0; k < 4; k++) {
                        temp.push_back({i, j, finalMass, finalSpeed, notDir[k]});
                    }
                }
            }
        }
        v = temp;
    }

    int answer = 0;
    for (int i = 0; i < v.size(); i++) answer += v[i].mass;
    cout << answer << "\n";
    return 0;
}