#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, answer = 0;
bool alpha[26];
vector<string> str;

void dfs(int idx, int depth) {
    if (depth == K) {
        int cnt = 0;
        bool read;

        for (int i = 0; i < str.size(); i++) {
            read = true;
            for (int j = 0; j < str[i].length(); j++) {
                if (!alpha[str[i][j] - 'a']) {
                    read = false;
                    break;
                }
            }
            if (read) cnt++;
        }

        answer = max(answer, cnt);
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (!alpha[i]) {
            alpha[i] = true;
            dfs(i, depth + 1);
            alpha[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    str.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    if (K < 5) {
        cout << 0 << "\n";
        return 0;
    }

    alpha['a' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['c' - 'a'] = true;
    K -= 5;

    dfs(0, 0);

    cout << answer << "\n";
    return 0;
}