#include <iostream>
#include <functional>

using namespace std;

int N, K, ans;
int money[15];

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &money[i]);
    }

    sort(money, money + N, greater<>());

    int i = 0;
    while (K != 0)
    {
        if (K < money[i])
            i++;
        else
        {
            K -= money[i];
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}