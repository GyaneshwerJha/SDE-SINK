class Solution {
public:
    static bool comparator(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            string curr = to_string(nums[i]);
            for(int j = 0; j < curr.size(); j++){
                int a = curr[j] - '0';
                curr[j] = (mapping[a] + '0');
            }
            mp[i] = stoi(curr);
        }

        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<endl;
        }

        vector<pair<int, int>> arr;
        for(auto it : mp){
            arr.push_back(it);
        }

        sort(arr.begin(), arr.end(), comparator);
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            int num = arr[i].first;
            ans.push_back(nums[num]);
        }

        return ans;
    }
};