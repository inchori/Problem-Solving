#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> dist;
vector<pair<int, int>> v[55];

void dijkstra(int N) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    dist[1] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        
        pq.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int nCost = v[now][i].second;
 
            if (dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.resize(N + 1, 1e9);
    for (int i = 0; i < road.size(); i++) {
        v[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    dijkstra(N);
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }
    return answer;
}