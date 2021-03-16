class Solution {
public:
    int answer = 0;
    int diff = 0;
    queue<pair<string, int>> q;
    bool visited[5005];
    
    void bfs(string beginWord, string endWord, vector<string>& wordList) {
        q.push(make_pair(beginWord, 0));
        while (!q.empty()) {
            pair<string, int> now = q.front();
            q.pop();
            
            if (now.first == endWord) {
                answer = now.second + 1;
                return;
            }
            
            for (int i = 0; i < wordList.size(); i++) {
                diff = 0;
                if (!visited[i]) {
                    for (int j = 0; j < wordList[i].length(); j++) {
                        if (now.first[j] != wordList[i][j]) {
                            diff++;
                        }
                    }
                }
                if (diff == 1) {
                    q.push(make_pair(wordList[i], now.second + 1));
                    visited[i] = true;
                }
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bfs(beginWord, endWord, wordList);
        return answer;
    }
};