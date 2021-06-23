#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
vector<pair<int, int> > m;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;
        m.push_back(make_pair(from, to));
    }

    sort(m.begin(), m.end(), cmp);

    int cnt = 0;
    int next = 0;

    for (int i = 0; i < m.size(); i++) {
        if (next <= m[i].first) {
            cnt++;
            next = m[i].second;
        }
    }

    cout << cnt << "\n";
    return 0;
}