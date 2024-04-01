class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        int len = 0;
        
        while(n >= 0 && s[n] == ' '){
            n--;
        }

        int high = n;

        while(n >= 0 && s[n] != ' '){
            n--;
            len++;
        }

        return len;

        
    }
};