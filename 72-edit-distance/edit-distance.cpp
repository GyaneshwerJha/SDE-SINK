class Solution {
public:

    int minDis(string word1, string word2, int i, int j, vector<vector<int>> &memo){
        if(i == 0){
            return j;
        }

        if(j == 0){
            return i;
        }

        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i - 1] == word2[j - 1]){
            return memo[i][j] = 0 + minDis(word1, word2, i - 1, j - 1, memo);
        }
        else{
            int ins =  1 + minDis(word1, word2, i, j - 1, memo);
            int del =  1 + minDis(word1, word2, i - 1, j, memo);
            int rep = 1 + minDis(word1, word2, i - 1, j - 1, memo);
            return memo[i][j] = min(ins, min(del, rep));
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        // return minDis(word1, word2, m, n, memo);


        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // initialize base case
        for(int i = 0; i < m + 1; i++){
            dp[i][0] = i;
        }

        for(int j = 0; j < n + 1; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                }
                else{
                    int ins =  1 + dp[i][j - 1];
                    int del =  1 + dp[i - 1][j];
                    int rep = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(ins, min(del, rep));
                }
            }
        }

        return dp[m][n];
    }
};