#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<string, int> m;
unordered_map<int, string> m2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string pokemon;
        cin >> pokemon;
        m[pokemon] = i + 1;
        m2[i + 1] = pokemon;
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            cout << m2[stoi(s)] << "\n";
        } else cout << m[s] << "\n";
    }
    return 0;
}