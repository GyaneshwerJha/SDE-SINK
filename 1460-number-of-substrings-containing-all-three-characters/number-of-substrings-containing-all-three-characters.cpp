class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['b'] = 0;
        mp['c'] = 0;

        int i = 0, j = 0;
        int cnt = 0;
        int gCnt = 0;
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]++;
                if(mp[s[j]] == 1){
                    cnt++;
                }
            }

            while(cnt == 3){
                gCnt += n - j;
                mp[s[i]]--;
                if(mp[s[i]] == 0) cnt--;
                i++;
            }
            j++;
        }

        return gCnt;
    }
};