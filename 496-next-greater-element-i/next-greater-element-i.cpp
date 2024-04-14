class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;
        vector<int> v;
        unordered_map<int, int> mp;
        for(int i = n2 - 1; i >= 0; i--){
            if(st.empty()){
                v.push_back(-1);
            }
            else if(!st.empty() && st.top() < nums2[i]){
                while(!st.empty() && st.top() < nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }
            }
            else{
                v.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < n2; i++){
            mp[nums2[i]] = v[i];
        }

        vector<int> ans;
        for(int i = 0; i < n1; i++){
            if(mp.find(nums1[i]) != mp.end()){
                ans.push_back(mp[nums1[i]]);
            }
        }

        return ans;

    }
};