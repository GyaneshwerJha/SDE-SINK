class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        multiset<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
            if(st.size() == k){
                int maxEle = *st.rbegin();
                ans.push_back(maxEle);
                int delInd = i - k + 1;
                    st.erase(st.find(nums[delInd]));
            }
        }
 
        return ans;
    }
};