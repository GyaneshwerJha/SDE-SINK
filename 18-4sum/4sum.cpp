class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    long long int sum = (long long int)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        int kVal = nums[k];
                        int lVal = nums[l];

                        while(k < l && nums[k] == kVal){
                            k++;
                        }
                        while(k < l && nums[l] == lVal){
                            l--;
                        }
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
        return res;
    }
};