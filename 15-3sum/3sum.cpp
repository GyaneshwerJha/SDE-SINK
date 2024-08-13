class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int k = 0; k < n; k++){
            int i = k + 1;
            int j = n - 1;
            int kVal = nums[k];

            while(i < j){
                if(kVal + nums[i] + nums[j] == 0){
                    ans.push_back({kVal, nums[i], nums[j]});
                    while(i + 1 < j && nums[i] == nums[i + 1]){
                        i++;
                    }
                    while(i + 1 < j && nums[j] == nums[j - 1]){
                        j--;
                    }
                    i++;
                    j--;
                }
                else if(nums[i] + nums[j] + kVal > 0){
                    j--;
                }
                else{
                    i++;
                }
            }
            while(k + 1 < n && nums[k] == nums[k + 1]){
                k++;
            }
        }
        return ans;
    }
};