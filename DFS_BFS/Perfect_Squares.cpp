#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> squares;
    queue<pair<int, int>> q;
    bool visited[10005];
    int answer;
    
    void bfs(int n) {
        q.push(make_pair(n, 0));
        visited[n] = true;
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            if (now.first == 0) {
                answer = now.second;
                return;
            }
            for (int i = 0; i < squares.size(); i++) {
                if (now.first - squares[i] >= 0 && !visited[now.first - squares[i]]) {
                    visited[now.first - squares[i]] = true;
                    q.push(make_pair(now.first - squares[i], now.second + 1));
                }
            }
        }
    }
    
    int numSquares(int n) {
        for (int i = 1; i <= n; i++) {
            if (i * i == pow(i, 2) && pow(i, 2) <= n) squares.push_back(pow(i, 2));
        }
        bfs(n);
        return answer;
    }
};