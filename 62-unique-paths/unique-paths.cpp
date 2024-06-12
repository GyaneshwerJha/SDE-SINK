class Solution {
public:
    // int way;
    int solve(int m, int n, vector<vector<int>> &memo){
        if(m < 0 || n < 0) return 0;

        if(m == 0 && n == 0){
            return 1;
        }

        if(memo[m][n] != -1) return memo[m][n];
        
        int left = solve(m - 1, n, memo);
        int top = solve(m, n - 1, memo);

        return memo[m][n] = left + top;
    }

    int uniquePaths(int m, int n) {
        // way = 0;
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return solve(m - 1, n - 1, memo);


        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }

        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int left = dp[i - 1][j];
                int top = dp[i][j - 1];
                dp[i][j] = left + top;
            }
        }

        return dp[m - 1][n - 1];

    }
};