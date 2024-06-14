class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int minIncre = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i - 1]){
                int increment = abs(nums[i] - nums[i - 1]) + 1;
                minIncre += increment;
                nums[i] += increment;
            }
        }

        // 1 1 2 2 3 7
        // 1 2 3 2 3 7 
        for(int i = 0; i < n; i++){
            cout<<nums[i]<<" ";
        }
        
        return minIncre;


    }
};