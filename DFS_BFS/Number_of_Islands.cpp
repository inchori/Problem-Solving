#include <vector>

using namespace std;

class Solution {
public:
    bool visited[305][305];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[nx].size()) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == '1') dfs(nx, ny, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid);
                    answer++;
                } else continue;
            }
        }
        return answer;
    }
};