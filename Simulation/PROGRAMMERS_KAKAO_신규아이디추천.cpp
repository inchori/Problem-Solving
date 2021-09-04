#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = tolower(new_id[i]);
    }
    string temp = "";
    
    for (int i = 0; i < new_id.length(); i++) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            temp += new_id[i];
        }
        else continue;
    }
    
    string temp2 = "";
    int dotCnt = 0;
    bool flag = false;
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == '.') {
            dotCnt++;
            flag = true;
        } else {
            if (dotCnt >= 1 && flag) {
                temp2 += '.';
            }
            temp2 += temp[i];
            flag = false;
            dotCnt = 0;
        }  
    }
    
    if (dotCnt >= 1 && flag) temp2 += '.';
    
    if (temp2[0] == '.') temp2.erase(0, 1);
    if (temp2[temp2.length() - 1] == '.') temp2.erase(temp2.length() - 1, 1);
    
    if (temp2 == "") temp2 += 'a';
    
    string temp3 = "";
    
    if (temp2.length() >= 16) {
        for (int i = 0; i < 15; i++) {
            temp3 += temp2[i];
        }
        if (temp3[temp3.length() - 1] == '.') temp3.erase(temp3.length() - 1, 1);
    } else temp3 = temp2;
    
    if (temp3.length() <= 2) {
        while (temp3.length() != 3) temp3 += temp3[temp3.length() - 1];
    }
    return temp3;
}