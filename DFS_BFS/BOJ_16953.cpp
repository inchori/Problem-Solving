#include <iostream>
#include <queue>

using namespace std;

long long a, b, answer = -1;
queue<pair<long long, long long> > q;

void bfs(int start, int b)
{
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == b)
        {
            answer = cnt;
            return;
        }

        if ((now * 2) <= b)
        {
            q.push(make_pair(now * 2, cnt + 1));
        }

        string temp = to_string(now) + '1';
        long long addOne = stoll(temp);

        if (addOne <= b)
        {
            q.push(make_pair(addOne, cnt + 1));
        }
    }
}

int main()
{
    scanf("%lld %lld", &a, &b);
    bfs(a, b);
    if (answer == -1)
    {
        printf("%lld\n", answer);
    }
    else
        printf("%lld\n", answer + 1);
    return 0;
}