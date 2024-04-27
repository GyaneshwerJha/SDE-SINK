class Solution {
public:
   int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& memo) {
    if (row == 0 && col == 0) {
        return grid[row][col];
    }

    if (memo[row][col] != -1) {
        return memo[row][col];
    }

    int up = (row > 0) ? solve(row - 1, col, grid, memo) : INT_MAX;
    int left = (col > 0) ? solve(row, col - 1, grid, memo) : INT_MAX;

    return memo[row][col] = grid[row][col] + min(up, left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // int minSum = 0;
        // vector<vector<int>> memo(row, vector<int>(col, -1));
        // return solve(row - 1, col - 1, grid, memo);
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};