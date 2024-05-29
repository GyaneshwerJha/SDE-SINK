class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mProduct = INT_MIN;
        for(int i = 0; i < n; i++){
            int tProduct = 1;
            for(int j = i; j < n; j++){
                tProduct *= nums[j];
                mProduct = max(mProduct, tProduct);
            }
        }

        return mProduct == INT_MIN ? nums[0] : mProduct;
    }
};