#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, M, lo = INT_MAX, hi;
int sangeun[500005], check[500005];
vector<int> answer;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &sangeun[i]);
    }
    sort(sangeun, sangeun + N);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &check[i]);
    }

    for (int i = 0; i < M; i++) {
        int lo = 0, hi = N - 1;
        bool flag = false;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (sangeun[mid] < check[i]) {
                lo = mid + 1;
            } else if (sangeun[mid] > check[i]) {
                hi = mid - 1;
            } else {
                flag = true;
                break;
            }
        }
        if (flag) answer.push_back(1);
        else answer.push_back(0);
    }

    for (int i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    return 0;
}