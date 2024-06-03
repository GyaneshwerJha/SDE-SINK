class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int xorr = -1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                if(xorr == -1){
                    xorr = nums[i];
                }
                else{
                    xorr ^= nums[i];
                }
            }
        }

        return xorr == -1 ? 0 : xorr;
    }
};