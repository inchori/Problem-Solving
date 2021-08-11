#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s < n) return {-1};

    int basic = s / n;
    int extra = s % n;
    answer.assign(n, basic);
    
    for (int i = answer.size() - 1; i >= 0 && extra > 0; i--) {
        answer[i]++;
        extra--;
    }
    return answer;
}