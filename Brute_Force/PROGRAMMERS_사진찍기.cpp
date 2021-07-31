#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> kakao = {"A", "C", "F", "J", "M", "N", "R", "T"};
bool visited[10];
int answer;

void dfs(int depth, string temp, vector<string> data) {
    if (depth == 8) {
        for (int i = 0; i < data.size(); i++) {
            char N1 = data[i][0];
            char N2 = data[i][2];
            char Cond = data[i][3];
            int Dist = data[i][4] - '0';
            Dist++;

            int idx1 = -1, idx2 = -1;
            for (int j = 0; j < 8; j++) {
                if (temp[j] == N1) idx1 = j;
                if (temp[j] == N2) idx2 = j;
                if (idx1 != -1 && idx2 != -1) break;
            }
            if (Cond == '=' && abs(idx1 - idx2) != Dist) return;
            if (Cond == '>' && abs(idx1 - idx2) <= Dist) return;
            if (Cond == '<' && abs(idx1 - idx2) >= Dist) return;
        }
        answer++;
        return;
    }
    for (int i = 0; i < kakao.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp += kakao[i];
            dfs(depth + 1, temp, data);
            visited[i] = false;
            temp.pop_back();
        }
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    dfs(0, "", data);
    return answer;
}