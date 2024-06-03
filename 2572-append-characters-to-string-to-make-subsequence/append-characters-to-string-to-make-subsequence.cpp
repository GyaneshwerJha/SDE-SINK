class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();

        int extraChar = 0;

        int i = 0;
        int j = 0;
        while(i < n){
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }

        return m - j;
    }
};