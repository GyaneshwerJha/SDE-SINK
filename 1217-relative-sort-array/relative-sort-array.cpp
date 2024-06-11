class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        map<int, int> mp;
        sort(arr1.begin(), arr1.end());
        vector<int> res;
        for(int i = 0; i < n; i++){
            mp[arr1[i]]++;
        }

        for(int i = 0; i < m; i++){
            int times = mp[arr2[i]];
            for(int j = 0; j < times; j++){
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        for(int i = 0; i < n; i++){
            if(mp[arr1[i]] != 0){
                int times = mp[arr1[i]];
                for(int j = 0; j < times; j++){
                    res.push_back(arr1[i]);
                    mp[arr1[i]]--;
                }
            }
        }

        return res;
    }
};