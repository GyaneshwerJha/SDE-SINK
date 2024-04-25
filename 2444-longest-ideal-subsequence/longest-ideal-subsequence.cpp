class Solution {
public:
    int lis(int n, string s, int k, string &ans, int prevChar, vector<vector<int>> &memo){
        if(n == 0){
            return 0;
        }

        if(memo[n - 1][prevChar] != -1) return memo[n - 1][prevChar];

        // take
        int take = 0;
        if(abs(s[n - 1] - prevChar) <= k || prevChar == 0){
            take =  1 + lis(n - 1, s, k, ans, s[n - 1], memo);
        }
        
        // not take
        int notTake =  0 + lis(n - 1, s, k, ans, prevChar, memo);

        return memo[n - 1][prevChar] = max(take, notTake);
    }

    int longestIdealString(string s, int k) {
        int n = s.size();
        string ans = "";
        // int prevChar = 0;
        // vector<vector<int>> memo(n + 1, vector<int>(256, -1));
        // return lis(n, s, k, ans, prevChar, memo);


        vector<vector<int>> dp(n + 1, vector<int>(256, 0));
        for(int i = 0; i < 256; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < 256; j++){
                int take = 0;
                if(abs(s[i - 1] - j) <= k){
                    take =  1 + dp[i - 1][s[i-1]];
                }
                // not take
                int notTake =  dp[i - 1][j];
                dp[i][j] = max(take, notTake);
            }
        }

        int maxLength = 0;
        for(int j = 0; j < 256; j++){
            maxLength = max(maxLength, dp[n][j]);
        }

        return maxLength;
        
    }
};