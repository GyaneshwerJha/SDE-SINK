class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int m_ele = *max_element(nums.begin(), nums.end());

        int ans = 0, len = 0;
        for(int ele : nums){
            if(ele == m_ele){
                len++;
                ans = max(ans, len);
            }
            else{
                len = 0;
            }
        }

        return ans;
    }
};