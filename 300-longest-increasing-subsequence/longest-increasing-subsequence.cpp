class Solution {
public:
    int solve(int ind, int n, vector<int> &nums, vector<int> &temp, int prev, vector<vector<int>> &memo){
        if(ind == n){
            return memo[ind][prev + 1] = 0;
        }

        if(memo[ind][prev + 1] != -1) return memo[ind][prev + 1];

        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            temp.push_back(nums[ind]);
            take = 1 + solve(ind + 1, n, nums, temp, ind, memo);
            temp.pop_back();
        }

        int notTake = 0 + solve(ind + 1, n, nums, temp, prev, memo);
        
        return memo[ind][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int ind = 0;
        vector<int> temp;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return solve(ind, n, nums, temp, prev, memo);
    }
};