#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> u;
unordered_map<string, int> ans;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++) {
        u[enroll[i]] = i;
    }

    for (int i = 0; i < seller.size(); i++) {
        int total = amount[i] * 100;
        string temp = seller[i];
        int recom_cost = total * 0.1;
        ans[temp] += total * 0.9;

        while (referral[u[temp]] != "-" || recom_cost != 0) {
            ans[referral[u[temp]]] += recom_cost - int(recom_cost * 0.1);
            if (recom_cost == 0) break;
            recom_cost *= 0.1;
            temp = referral[u[temp]];
        }
    }
    
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(ans[enroll[i]]);
    }
    return answer;
}