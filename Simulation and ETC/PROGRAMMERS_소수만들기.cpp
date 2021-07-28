#include <vector>
#include <iostream>

using namespace std;

bool prime[3005];

void isPrime() {
    for (int i = 2; i <= 3005; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= 3005; j += i) {
                prime[j] = true;
            }
        }   
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    isPrime();
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (!prime[sum]) {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}