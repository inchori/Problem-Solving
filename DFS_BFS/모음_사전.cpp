#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
vector<string> dict;

void dfs(string now, int len) {
    if (now.length() == len) {
        dict.push_back(now);
        return;
    }
    for (char vowel : vowels) {
        dfs(now + vowel, len);
    }
}

int solution(string word) {
    for (int i = 1; i <= 5; i++) {
        string nowWord = "";
        dfs(nowWord, i);
    }
    
    sort(dict.begin(), dict.end());
    
    for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == word) return i + 1;
    }
}