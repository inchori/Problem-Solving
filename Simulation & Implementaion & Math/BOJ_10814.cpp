#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<pair<int, string>, int> > v;

bool cmp(const pair<pair<int, string>, int> &a, const pair<pair<int, string>, int> &b)
{
    if (a.first.first == b.first.first)
        return a.second < b.second;
    return a.first.first < b.first.first;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x;
        string name;
        cin >> x >> name;
        v.push_back(make_pair(make_pair(x, name), i));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first.first << " " << v[i].first.second << "\n";
    }
    return 0;
}