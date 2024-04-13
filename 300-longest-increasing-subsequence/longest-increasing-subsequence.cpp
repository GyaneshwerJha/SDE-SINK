class Solution {
public:
    int LIS(int ind, int n, int prev_ind, vector<int> &nums, vector<vector<int>> &memo){
        if(ind == n) return 0;

        if(memo[ind][prev_ind + 1] != -1) return memo[ind][prev_ind + 1];

        // take
        int take = 0; 
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            take = 1 + LIS(ind + 1, n, ind, nums, memo);
        }

        // not take
        int notTake = LIS(ind + 1, n, prev_ind, nums, memo);

        return memo[ind][prev_ind + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return LIS(0, n, -1, nums, memo);
    }
};
