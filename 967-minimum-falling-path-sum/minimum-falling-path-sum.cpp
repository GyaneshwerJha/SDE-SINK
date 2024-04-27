class Solution {
public:
    int n = -1, m = -1;
    int minSum(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &memo){
        if(j < 0 || j >= m) return 1e8;
        if(i == 0) return matrix[i][j];

        if(memo[i][j] != -1) return memo[i][j];

        int up = matrix[i][j] + minSum(i - 1, j, matrix, memo);
        int right = matrix[i][j] + minSum(i - 1, j + 1, matrix, memo);
        int down = matrix[i][j] + minSum(i - 1, j - 1, matrix, memo);

        return memo[i][j] = min(up, min(right, down));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        // vector<vector<int>> memo(n, vector<int>(m, -1));
        // int mini = INT_MAX;
        // for(int j = 0; j < m; j++){
        //     mini = min(mini, minSum(n - 1, j, matrix, memo));
        // }
        // return mini;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = matrix[i][j] + dp[i - 1][j];
                int right = matrix[i][j];
                if(j + 1 < m){
                    right += dp[i - 1][j + 1];
                }
                else{
                    right += 1e8;
                }
                int left = matrix[i][j];
                if(j - 1 >= 0){
                    left += dp[i - 1][j - 1];
                }
                else{
                    left += 1e8;
                }
                dp[i][j] = min(up, min(right, left));
            }
        }

        
        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            mini = min(mini, dp[n -1][j]);
        }

        return mini;

    }
};