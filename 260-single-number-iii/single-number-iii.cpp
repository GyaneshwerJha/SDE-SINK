class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 1;
        if(nums[0] != nums[1]){
            ans.push_back(nums[0]);
        }

        if(nums[n - 1] != nums[n - 2]){
            ans.push_back(nums[n - 1]);
        }
        while(i < n - 1){
            if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]){
                ans.push_back(nums[i]);
            }
            i++;
        }

        return ans;
    }
};