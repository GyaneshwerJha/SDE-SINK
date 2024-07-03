class Solution {
public:
    int solve(int n, vector<int> &memo){
        if(n < 0) return 0;
        if(n == 0){
            return memo[n] = 1;
        }

        if(memo[n] != -1) return memo[n];

        int byOne = solve(n - 1, memo);
        int byTwo = solve(n - 2, memo);
        return memo[n] = byOne + byTwo;

    }

    int climbStairs(int n) {
        // vector<int> memo(n + 1, -1);
        // return solve(n, memo);

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++){
            int byOne = dp[i - 1];
            int byTwo = dp[i - 2];
            dp[i] = byOne + byTwo;
        }

        return dp[n];
    }
};