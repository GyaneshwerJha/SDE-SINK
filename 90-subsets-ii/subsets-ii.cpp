class Solution {
public:
    vector<vector<int>> ans;
    void subsetSum(vector<int> &temp, int index, int n, vector<int> &nums){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        // take 
        temp.push_back(nums[index]);
        subsetSum(temp, index + 1, n, nums);
        temp.pop_back();

        // skip duplicates
        while(index + 1 < n && nums[index] == nums[index + 1]){
            index++;
        }

        // not take
        subsetSum(temp, index + 1, n, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        subsetSum(temp, 0, n, nums);
        sort(ans.begin(), ans.end());
        return ans;
    }
};