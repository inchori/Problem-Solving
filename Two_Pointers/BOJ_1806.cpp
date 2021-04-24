#include <iostream>
#include <climits>

using namespace std;

int n, s;
int MIN = INT_MAX;
int arr[100005];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 0, j = 0;
    int sum = arr[0];
    while (i <= j && j < n) {
        if (sum == s) {
            MIN = min(MIN, j - i + 1);
            j++;
            sum += arr[j];
            continue;
        }
        if (sum < s) {
            j++;
            sum += arr[j];
            continue;
        }
        if (sum > s) {
            MIN = min(MIN, j - i + 1);
            sum -= arr[i];
            i++;
            continue;
        }
    }


    if (MIN == INT_MAX) printf("0\n");
    else printf("%d\n", MIN);
    return 0;
}