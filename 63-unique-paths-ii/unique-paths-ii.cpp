class Solution {
public:
vector<vector<int>> dp;
int f(vector<vector<int>>& obstacleGrid, int i, int j){
    int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
    if(i>=m || j>=n) return 0;
    if(obstacleGrid[i][j]==1) return 0;
    if(i==m-1 && j==n-1) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int right = f(obstacleGrid, i,j+1);
    int down = f(obstacleGrid, i+1,j);
    return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.assign(m, vector<int>(n, -1));
        return f(obstacleGrid, 0, 0);
    }
};