class Solution {
public:
    int solve(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;

        return solve(n - 1) + solve(n - 2);
    }

    int climbStairs(int n) {
        // int ind = 0;
        // return solve(n);
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i < n + 1; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};