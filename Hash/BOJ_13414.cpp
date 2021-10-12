#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int K, L;
unordered_map<string, int> m;
vector<string> dic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        string studentID;
        cin >> studentID;
        dic.push_back(studentID);
        m[studentID] = i;
    }

    int cnt = 0;
    for (int i = 0; i < L; i++) {
        if (cnt >= K) break;
        if (m[dic[i]] == i) {
            cout << dic[i] << "\n";
            cnt++;
        }
    }

    return 0;
}