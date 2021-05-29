class Solution {
public:
    vector<int> temp;
    int cnt = 0;
    int make_binary(int a) {
        while (a != 0) {
            temp.push_back(a % 2);
            a /= 2;
        }

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 1) cnt++;
        }

        return cnt;
    }


    vector<int> countBits(int num) {
        vector<int> answer;
        for (int i = 0; i <= num; i++) {
            answer.push_back(make_binary(i));
            temp.clear();
            cnt = 0;
        }

        return answer;
    }
};