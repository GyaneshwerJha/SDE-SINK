class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int xorr = nums[0];

        for(int i = 1; i < n; i++){
            xorr ^= nums[i];
        }

        xorr ^= k;
        return __builtin_popcount(xorr);
    }
};