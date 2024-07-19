class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNums;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            
            int minRowVal = INT_MAX;
            int minRowIdx = -1;
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] < minRowVal) {
                    minRowVal = matrix[i][j];
                    minRowIdx = j;
                }
            }

            
            bool isLucky = true;
            for (int k = 0; k < n; ++k) {
                if (matrix[k][minRowIdx] > minRowVal) {
                    isLucky = false;
                    break;
                }
            }

            
            if (isLucky) {
                luckyNums.push_back(minRowVal);
            }
        }

        return luckyNums;
    }
};