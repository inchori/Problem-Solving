#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int depth, int sum) {
    if (depth == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    dfs(numbers, target, depth + 1, sum + numbers[depth]);
    dfs(numbers, target, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}