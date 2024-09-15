class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        set<int> st;
        for(int num : nums){
            if(st.find(num) != st.end()){
                ans.push_back(num);
            }
            st.insert(num);
        }   

        return ans;
    }
};