class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOp = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i - 1]){
                minOp += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i] + nums[i - 1] - nums[i] + 1;
            }
        }

        for(int i = 0; i < n; i++){
            cout<<nums[i]<<" ";
        }

        return minOp;
    }
};