#include <iostream>

using namespace std;

int N;
string s1 = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
string s2 = "\"재귀함수가 뭔가요?\"";
string s3 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string s4 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string s5 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string s6 = "라고 답변하였지.";

void bar(int n) {
    for (int i = 0; i < N - n; i++) {
        cout << "____";
    }
}

void go(int n) {
    bar(n);
    cout << s2 << "\n";
    if (n == 0) {
        bar(n);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
        bar(n);
        cout << s6 << "\n";
        return;
    }
    bar(n);
    cout << s3 << "\n";
    bar(n);
    cout << s4 << "\n";
    bar(n);
    cout << s5 << "\n";
    go(n - 1);
    bar(n);
    cout << s6 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    cout << s1 << "\n";
    go(N);
    return 0;
}