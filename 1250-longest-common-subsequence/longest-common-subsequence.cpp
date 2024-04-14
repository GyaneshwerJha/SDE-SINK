class Solution {
public:
    int lcs(int m, int n, string text1, string text2, vector<vector<int>> &memo){
        if(m == 0 || n == 0) return 0;

        if(memo[m][n] != -1) return memo[m][n];
        if(text1[m - 1] == text2[n - 1]){
            return memo[m][n] = 1 + lcs(m - 1, n - 1, text1, text2, memo);
        }

        return memo[m][n] = max(lcs(m - 1, n, text1, text2, memo), lcs(m, n - 1, text1, text2, memo));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        // return lcs(m, n, text1, text2, memo);

        int dp[m + 1][n + 1];
        for(int i = 0; i < m + 1; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i < n + 1; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};