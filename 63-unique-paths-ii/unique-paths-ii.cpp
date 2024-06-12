class Solution {
public:

    int solve(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &memo){

        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1){
            return 0;
        }

        if(m == 0 && n == 0 && obstacleGrid[m][n] != 1){
            return 1;
        }

        if(memo[m][n] != -1) return memo[m][n];
        int top = solve(m - 1, n, obstacleGrid, memo);
        int left = solve(m, n - 1, obstacleGrid, memo);
        return memo[m][n] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0)); // Initialize dp array

    // Check if starting point is obstacle, return 0 if so
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // Initialize base cases for the first row and column
    dp[0][0] = 1; // Starting point
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] != 1){
            dp[i][0] = dp[i - 1][0];
        }
    }
    for(int i = 1; i < n; i++){
        if(obstacleGrid[0][i] != 1){
            dp[0][i] = dp[0][i - 1];
        }
    }

    // Populate dp array for the rest of the grid
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] != 1){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1]; // Return the count of unique paths
}
};