class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                temp[j][i] = matrix[matrix.size() - i - 1][j];
            }
        }
        matrix = temp;
    }
};