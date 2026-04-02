class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;

        for (int i = 0; i < matrix.size(); i++) {
            
            int minVal = matrix[i][0];
            int col = 0;

            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    col = j;
                }
            }
            
            bool isLucky = true;

            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][col] > minVal) {
                    isLucky = false;
                    break;
                }
            }


            if (isLucky) {
                ans.push_back(minVal);
            }
        }

        return ans;
    }
};