class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        int cntBeauty = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> mp;
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                if(mp.size() >= 2){
                    int maxi = INT_MIN;
                    int mini = INT_MAX;
                    for(auto it : mp){
                        maxi = max(maxi, it.second);
                        mini = min(mini, it.second);
                    }
                    cntBeauty += (maxi - mini);
                }
            }
        }

        return cntBeauty;
    }
};