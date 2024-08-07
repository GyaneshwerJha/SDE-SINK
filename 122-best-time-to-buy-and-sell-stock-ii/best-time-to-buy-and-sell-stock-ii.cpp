class Solution {
public:
    int profit = 0;
    int solve(int ind, bool canBuy, vector<int> &prices, vector<vector<int>> &memo){
        if(ind == prices.size()){
            return 0;
        }

        if(memo[ind][canBuy] != -1) return memo[ind][canBuy];

        // can buy 
        if(canBuy){
            // want to buy 
            int take = -prices[ind] + solve(ind + 1, !canBuy, prices, memo);
            
            // do not want to buy
            int notTake = 0 + solve(ind + 1, canBuy, prices, memo);

            profit = max(take, notTake);
        }
        else{ // can not buy
            // want to sell
            int take = prices[ind] + solve(ind + 1, !canBuy, prices, memo);

            // do not want to sell
            int notTake = 0 + solve(ind + 1, canBuy, prices, memo);

            profit = max(take, notTake);
        }

        return memo[ind][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int ind = 0;
        // bool canBuy = 1;
        // vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        // return solve(ind, canBuy, prices, memo);
    
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        
        // initialize base case
        dp[n][0] = dp[n][1] = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                if(canBuy){
                // want to buy 
                    int take = -prices[i] + dp[i + 1][!canBuy];                    
                    // do not want to buy
                    int notTake = 0 + dp[i + 1][canBuy];

                    dp[i][canBuy] = max(take, notTake);
                }
                else{ // can not buy
                    // want to sell
                    int take = prices[i] + dp[i + 1][!canBuy];

                    // do not want to sell
                    int notTake = 0 + dp[i + 1][canBuy];

                    dp[i][canBuy] = max(take, notTake);
                }
            }
        }

        return dp[0][1];

    }
};