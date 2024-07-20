class Solution {
public:
    int solve(int idx, int amount, vector<int> &coins){
        if(idx == 0){
            return 0;
        }

        if(amount == 0){
            return 1;
        }

        int take = 0;
        if(amount >= coins[idx - 1]){
            take = solve(idx, amount - coins[idx - 1], coins);
        }

        int notTake = solve(idx - 1 , amount, coins);
        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solve(n, amount, coins);

        int dp[n + 1][amount + 1];
        for(int i = 0; i < amount + 1; i++){
            dp[0][i] = 0;
        }

        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                int take = 0;
                if(j >= coins[i - 1]){
                    take = dp[i][j - coins[i - 1]];
                }

                int notTake = dp[i - 1][j];
                dp[i][j] = take + notTake;
            }
            
        }
        return dp[n][amount];
    }
};