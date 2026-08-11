class Solution {
public:
    vector<vector<int>> dp;

    int f(int m, int n, int i, int j) {

        
        if(i == m - 1 && j == n - 1)
            return 1;

        
        if(i >= m || j >= n)
            return 0;

        
        if(dp[i][j] != -1)
            return dp[i][j];

        
        int down = f(m, n, i + 1, j);

        
        int right = f(m, n, i, j + 1);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {

        dp.assign(m, vector<int>(n, -1));

        return f(m, n, 0, 0);
    }
};