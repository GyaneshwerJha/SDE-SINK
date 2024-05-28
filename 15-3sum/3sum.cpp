class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            int iVal = nums[i];
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    res.push_back({nums[i], nums[j], nums[k]});
                    int jVal = nums[j];
                    int kVal = nums[k];
                    while(j + 1 < k && nums[j + 1] == jVal){
                        j++;
                    }
                    while(j < k && nums[k] == kVal){
                        k--;
                    }
                }
            }

            while(i + 1 < n && nums[i + 1] == iVal){
                i++;
            }
        }
        return res;
    }
};