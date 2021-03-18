#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double answer;
        vector<double> temp;
        for (int i = 0; i < nums1.size(); i++) {
            temp.push_back(nums1[i]);
        }
        
        for (int j = 0; j < nums2.size(); j++) {
            temp.push_back(nums2[j]);
        }
        
        sort(temp.begin(), temp.end());
        
        if (temp.size() == 1) {
            answer = temp[0];
        }
        
        else if (temp.size() % 2 != 0) {
            answer = temp[temp.size() / 2];
        }
        
        else if (temp.size() % 2 == 0) {
            answer = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2;
        }
        
        return answer;
    }
};