class Solution {
public:
    int bruteforce(vector<int> &nums){
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            int tempSum = 0;
            for(int j = i; j < n; j++){
                tempSum += nums[j];
                maxSum = max(maxSum, tempSum);
            }
        }

        return maxSum;
    }
    int maxSubArray(vector<int>& nums) {
        // return bruteforce(nums);
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if(sum < 0){
                sum = 0;
            }
        }

        return maxSum;
    }
};