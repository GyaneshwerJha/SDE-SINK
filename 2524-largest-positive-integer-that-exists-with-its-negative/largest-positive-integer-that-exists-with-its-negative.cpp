class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        int largeInt = INT_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0 && nums[i] > largeInt && st.find(-nums[i]) != st.end()){
                largeInt = nums[i];
            }
        }

        return largeInt == INT_MIN ? -1 : largeInt;
    }
};