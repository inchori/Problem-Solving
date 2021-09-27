#include <iostream>
#include <queue>

using namespace std;

int N, M, ans = 0;
int arr[55][55];
int cloud[55][55];
vector<pair<int, int>> q;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void makeCloud() {
    cloud[N - 1][0] = 1;
    cloud[N - 1][1] = 1;
    cloud[N - 2][0] = 1;
    cloud[N - 2][1] = 1;
    q.push_back(make_pair(N - 1, 0));
    q.push_back(make_pair(N - 1, 1));
    q.push_back(make_pair(N - 2, 0));
    q.push_back(make_pair(N - 2, 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    makeCloud();

    while (M--) {
        int start, move;
        cin >> start >> move;

        start--;
        memset(cloud, 0, sizeof(cloud));
        for (int i = 0; i < q.size(); i++) {
            int x = q[i].first;
            int y = q[i].second;
            int nx = x;
            int ny = y;
            for (int j = 0; j < move; j++) {
                nx += dx[start];
                ny += dy[start];
                if (nx < 0) nx = N - 1;
                if (ny < 0) ny = N - 1;
                if (nx >= N) nx = 0;
                if (ny >= N) ny = 0;
            }
            q[i].first = nx;
            q[i].second = ny;
        }

        for (int i = 0; i < q.size(); i++) {
            int x = q[i].first;
            int y = q[i].second;
            cloud[x][y] = true;
        }

        for (int i = 0; i < q.size(); i++) {
            arr[q[i].first][q[i].second]++;
        }

        for (int i = 0; i < q.size(); i++) {
            int x = q[i].first;
            int y = q[i].second;
            int cnt = 0;
            for (int j = 1; j <= 8; j += 2) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (arr[nx][ny] >= 1) cnt++;
                }
            }
            arr[x][y] += cnt;
        }

        q.clear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!cloud[i][j] && arr[i][j] >= 2) {
                    arr[i][j] -= 2;
                    q.push_back(make_pair(i, j));
                }
            }
        }

        memset(cloud, 0, sizeof(cloud));
        for (int i = 0; i < q.size(); i++) {
            cloud[q[i].first][q[i].second] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans << "\n";
    return 0;
}