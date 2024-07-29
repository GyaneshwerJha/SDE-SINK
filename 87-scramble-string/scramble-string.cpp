class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if (s1.empty() || s2.empty()) return false;
        if(s1 == s2) return true;

        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end()) return mp[key];

        bool result = false;
        int n = s1.length();
        for(int i = 1; i <= n - 1; i++){
            // swapped
            bool swapped = isScramble(s1.substr(i, n - i), s2.substr(0, n - i)) &&
                           isScramble(s1.substr(0, i), s2.substr(n - i, i));
            // not swapped
            bool notSwapped = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                              isScramble(s1.substr(i, n - i), s2.substr(i, n - i));

            if(swapped == true || notSwapped == true){
                result = true;
                break;
            }
        }

        return mp[key] = result;
    }
};