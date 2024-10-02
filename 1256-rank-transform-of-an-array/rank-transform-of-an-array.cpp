class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        unordered_map<int, int> mp;
        set<int> st;
        vector<int> arr(a.begin(), a.end());
        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size(); i++){
            st.insert(arr[i]);
        }

        int b = 1;
        for(auto it : st){
            // cout<<it<<" ";
            mp[it] = b++;
        }

        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }


        vector<int> ans;
        for(int i = 0; i < a.size(); i++){
            // cout<<a[i] <<" " << mp[a[i]]<<endl;
            ans.push_back(mp[a[i]]);
        }

        return ans;
    }
};