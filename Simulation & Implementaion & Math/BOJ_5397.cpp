#include <iostream>
#include <list>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        list<char> l;
        auto iter = l.begin();

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                if (iter != l.begin()) iter--;
            } else if (s[i] == '>') {
                if (iter != l.end()) iter++;
            } else if (s[i] == '-') {
                if (iter != l.begin()) {
                    iter--;
                    iter = l.erase(iter);
                }
            } else {
                l.insert(iter, s[i]);
            }
        }

        for (char c : l) cout << c;

        cout << "\n";
    }

    return 0;
}