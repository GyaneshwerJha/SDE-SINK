class Solution {
public:
    bool isAnagram(string s, string t) {
        /* using map
        int n = s.size();
        int m = t.size();
        if( n != m) return false;
        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        for(int i = 0; i < m; i++){
            mp[t[i]]--;
        }

        for(int i = 0; i < n; i++){
            if(mp[s[i]] > 0){
                return false;
            }
        }

        return true;
    */
    int n = s.size();
    int m = t.size();
    if(n != m){
        return false;
    }

    vector<int> v(26);
    for(int i = 0; i < n; i++){
        v[s[i] - 'a']++;
        v[t[i] - 'a']--;
    }

    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0) return false;
    }

    return true;
    }
};