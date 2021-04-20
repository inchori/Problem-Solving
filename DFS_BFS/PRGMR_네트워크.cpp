#include <string>
#include <vector>

using namespace std;

bool visited[205];

void dfs(int start, vector<vector<int> > graph)
{
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            dfs(next, graph);
        }
    }
}

int solution(int n, vector<vector<int> > computers)
{
    int answer = 0;

    vector<vector<int> > graph;
    graph.resize(n + 1);

    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (computers[i][j] == 1)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!visited[graph[i][j]])
            {
                dfs(graph[i][j], graph);
                answer++;
            }
        }
    }

    return answer;
}