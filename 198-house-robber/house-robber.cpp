class Solution {
public:
    int memo[100][101];
    int solve(int n, int prev, vector<int> &nums){
        if(n < 0) return 0;

        if(memo[n][prev + 1] != -1) return memo[n][prev + 1];
        // take
        int take = 0;
        if(prev == -1 || n + 1 != prev){
            take = nums[n] + solve(n - 1, n, nums); 
        }
        // not take
        int notTake = solve(n - 1, prev, nums);
        return memo[n][prev + 1] = max(take, notTake);
    }

    int rob(vector<int>& nums) { 
        memset(memo, -1, sizeof(memo));
        int n = nums.size();
        int prev = -1;
        int cost = solve(n - 1, prev, nums);
        return cost;
    }
};