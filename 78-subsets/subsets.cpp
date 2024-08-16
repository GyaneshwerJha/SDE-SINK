class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind, int n, vector<int> &temp, vector<int> &nums){
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(ind + 1, n, temp, nums);
        temp.pop_back();

        solve(ind + 1, n, temp, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        int n = nums.size();
        
        solve(0, n, temp, nums);
        return ans;
    }
};