#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    string temp2 = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= 'a' && new_id[i] <= 'z') ||
            (new_id[i] >= '0' && new_id[i] <= '9')) {
            temp += new_id[i];
        } else continue;
    }

    for (int i = 1; i < temp.length(); ) {
        if (temp[i] == '.' && temp[i - 1] == '.') {
            temp.erase(temp.begin() + i);
            continue;
        }
        else i++;
    }

    if (temp[0] == '.') temp.erase(0, 1);
    if (temp[temp.length() - 1] == '.') temp.erase(temp.length() - 1, 1);

    
    if (temp.length() == 0) temp += 'a';
    
    
    if (temp.length() >= 16) {
        for (int i = 0; i < 15; i++) {
            answer += temp[i];
        }
        if (answer.back() == '.') answer.erase(answer.end() - 1);
    }
    else if (temp.length() <= 2) {
        for (int i = 0; i < temp.length(); i++) {
            answer += temp[i];
        }
        int i = answer.length();
        while (i <= 2) {
            answer += temp[temp.length() - 1];
            i++;
        }
    }
    else answer = temp;
    return answer;
}