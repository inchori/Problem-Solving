#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<int> q;
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int temp = 0;
    cout << "<";
    while (true) {
        for (int i = 0; i < K - 1; i++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front();
        q.pop();
        if (q.empty()) break;
        cout << ", ";
    }
    cout << ">";
    return 0;
}