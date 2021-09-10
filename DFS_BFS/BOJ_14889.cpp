#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N, answer = INT_MAX;
int arr[25][25];
bool visited[25];
vector<int> start;
vector<int> link;

void dfs(int depth, int idx) {
    if (depth == N / 2) {

        link.clear(); start.clear();
        int startPoint = 0, linkPoint = 0;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) link.push_back(i);
            else start.push_back(i);
        }

        for (int i = 0; i < start.size(); i++) {
            for (int j = i + 1; j < start.size(); j++) {
                startPoint += arr[start[i]][start[j]] + arr[start[j]][start[i]];
            }
        }

        for (int i = 0; i < link.size(); i++) {
            for (int j = i + 1; j < link.size(); j++) {
                linkPoint += arr[link[i]][link[j]] + arr[link[j]][link[i]];
            }
        }

        answer = min(answer, abs(startPoint - linkPoint));
        return;
    }
    for (int i = idx; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 1);

    cout << answer << "\n";

    return 0;
}