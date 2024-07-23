class Solution {
public:
    static bool comparator(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> freqVector;
        for(auto it : mp){
            freqVector.push_back({it.first, it.second});
        }
        sort(freqVector.begin(), freqVector.end(), comparator);
        
        vector<int> ans;
        for(int i = 0; i < freqVector.size(); i++){
            int curr = freqVector[i].first;
            int cnt = freqVector[i].second;
            for(int j = 0; j < cnt; j++){
                ans.push_back(curr);
            }
        }

        return ans;
    }
};