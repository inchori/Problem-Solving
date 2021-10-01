#include <iostream>
#include <stack>
#include <climits>

using namespace std;

int N;
stack<pair<int, int>> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    st.push({INT_MAX, 0});
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        while (st.top().first < height) st.pop();
        cout << st.top().second << " ";
        st.push({height, i});
    }

    return 0;
}