class Solution {
public:

    int minSum(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &memo){
        if(n <= 0 || m <= 0) return 1e8;
        if(n - 1 == 0 && m - 1 == 0) return  grid[n - 1][m - 1];

        if(memo[n][m] != -1) return memo[n][m];

        int up = grid[n - 1][m - 1] +  minSum(n - 1, m, grid, memo);
        int down = grid[n - 1][m - 1] + minSum(n, m - 1, grid, memo);

        return memo[n][m] = min(up, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        // return minSum(n, m, grid, memo);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up = grid[i][j];
                    if(i > 0){
                        up += dp[i - 1][j];
                    }
                    else{
                        up = 1e8;
                    }

                    int down = grid[i][j];
                    if(j > 0){
                        down += dp[i][j - 1];
                    }
                    else{
                        down = 1e8;
                    }

                    dp[i][j] = min(up, down);
                }
            }
        }

        return dp[n - 1][m - 1];
        
    }
};