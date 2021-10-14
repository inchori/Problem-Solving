#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int N, M, answer = INT_MAX;
int arr[55][55];
bool visited[15];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> temp;

void getAnswer(int cur, int cnt) {
    if (cnt == M) {
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            int now = INT_MAX;
            for (int j = 0; j < temp.size(); j++) {
                now = min(now, abs(house[i].first - temp[j].first) + abs(house[i].second - temp[j].second));
            }
            sum += now;
        }
        answer = min(answer, sum);
        return;
    }

    for (int i = cur; i < chicken.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(chicken[i]);
            getAnswer(i + 1, cnt + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) house.push_back(make_pair(i, j));
            if (arr[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    getAnswer(0, 0);

    cout << answer << "\n";
    return 0;
}