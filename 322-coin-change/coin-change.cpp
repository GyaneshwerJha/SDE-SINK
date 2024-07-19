class Solution {
public:
    const int mod = 1e9;
    int solve(int idx, vector<int> &coins, int amount){
        if(amount == 0) return 0;
        if(idx == 0) return mod;
        int take = mod;
        if(amount >= coins[idx - 1]){
            take = 1 + solve(idx, coins, amount - coins[idx - 1]);
            cout<<take<<endl;
        }
        int notTake = solve(idx - 1, coins, amount);

        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int result = solve(n, coins, amount);
        // return result == mod ? -1 : result;

        int dp[n + 1][amount + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i < amount + 1; i++){
            dp[0][i] = mod;
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < amount + 1; j++){
                int take = mod;
                if(j >= coins[i - 1]){
                    take = 1 + dp[i][j - coins[i - 1]];
                    // cout<<take<<endl;
                }
                int notTake = dp[i - 1][j];

                dp[i][j] = min(take, notTake);
            }
        }
        if(dp[n][amount] == mod) return -1;
        return dp[n][amount];
    }
};