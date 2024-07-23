class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0, j = 0;
        long long maxSum = 0;
        long long sum = 0;
        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];
            while(j - i + 1 > k){
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(j - i + 1 == k && mp.size() == k){
                maxSum = max(maxSum, sum);
            }

        
            j++;
        }

        return maxSum;
    }
};