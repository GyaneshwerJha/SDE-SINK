class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long long int sum = (long long int)nums[i] + nums[j] + nums[k] + nums[l];
                    // cout<<sum;
                    if(sum > target){
                        l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k + 1 < l && nums[k] == nums[k + 1]){
                            k++;
                        }
                        while(k + 1 < l && nums[l] == nums[l - 1]){
                            l--;
                        }
                        k++;
                        l--;
                    }
                }
                while(j + 1 < n && nums[j] == nums[j + 1]){
                    j++;
                }
            }
            while(i + 1 < n && nums[i] == nums[i + 1]){
                i++;
            }
        }

        return ans;
    }
};