#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans, sum;
int arr[10];
vector<int> temp;
bool visited[10];

void go(int depth) {
    if (depth == N) {
        sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += abs(temp[i] - temp[i + 1]);
        }
        ans = max(ans, sum);
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(arr[i]);
            go(depth + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    go(0);
    printf("%d\n", ans);
    return 0;
}