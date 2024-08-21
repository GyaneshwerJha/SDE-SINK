class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int cnt0 = 0;
        int ans = 0;
        while(j < n){
            if(nums[j] == 0){
                cnt0++;
            }

            if(cnt0 <= k){
                ans = max(ans, j - i + 1);
            }

            while(i < j && cnt0 > k){
                if(nums[i] == 0){
                    cnt0--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};