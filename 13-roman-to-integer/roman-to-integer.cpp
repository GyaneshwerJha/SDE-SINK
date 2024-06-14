class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;


        int res = 0;
        for(int i = 0; i < n; i++){
            res += mp[s[i]];
            if(i > 0){
                if(mp[s[i - 1]] < mp[s[i]]){
                    res -= mp[s[i - 1]] + mp[s[i - 1]];
                }
            }
        }
        
        return res;
    }
};