#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> st;
int arr[100005];
int a[100005];
vector<char> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int now = 1;
    for (int i = 0; i < N; i++) {
        if (st.empty() || st.top() != arr[i]) {
            while (true) {
                if (now > N) {
                    cout << "NO\n";
                    return 0;
                }
                st.push(now++);
                ans.push_back('+');
                if (st.top() == arr[i]) {
                    st.pop();
                    ans.push_back('-');
                    break;
                }
            }
        } else if (st.top() == arr[i]) {
            st.pop();
            ans.push_back('-');
        }
    }

    for (auto c : ans) {
        cout << c << "\n";
    }
    return 0;
}