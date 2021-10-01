#include <iostream>
#include <deque>

using namespace std;

int N, M, ans = 0;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int idx;
    for (int i = 0; i < M; i++) {
        cin >> idx;
        int curr = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == idx) {
                curr = j;
                break;
            }
        }

        if (curr < dq.size() - curr) {
            while (true) {
                if (dq.front() == idx) {
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            while (true) {
                if (dq.front() == idx) {
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

    }

    cout << ans << "\n";
    return 0;
}