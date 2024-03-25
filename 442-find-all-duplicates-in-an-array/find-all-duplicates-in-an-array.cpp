class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int count = 1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                count++;
                if(count > 1){
                    ans.push_back(nums[i]);
                }
            }
            else{
                count = 1;
            }
        }

        return ans;
    }
};