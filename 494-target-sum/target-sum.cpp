class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if((sum + target) % 2 != 0) return 0;
        int s1 = (sum + target) / 2;
        if(s1 < 0) return 0;
        vector<vector<long long>> dp(n + 1, vector<long long> (s1 + 1, 0));
        dp[0][0] = 1;

        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < s1 + 1; j++){
                int take = 0;
                if(j >= nums[i - 1]){
                    take = dp[i - 1][j - nums[i - 1]];    
                }
                int notTake = dp[i - 1][j];
                dp[i][j] = take + notTake;
            }
        }
        return dp[n][s1];
    }
};