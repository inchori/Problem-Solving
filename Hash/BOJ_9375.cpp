#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        int N, answer = 1;
        cin >> N;
        unordered_map<string, int> m;
        for (int i = 0; i < N; i++) {
            string type, name;
            cin >> name >> type;
            m[type] += 1;
        }

        for (auto i: m) answer *= (i.second + 1);
        answer -= 1;
        cout << answer << "\n";
    }
    return 0;
}