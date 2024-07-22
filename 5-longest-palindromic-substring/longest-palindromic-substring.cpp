class Solution {
public:
    int memo[1001][1001];
    bool checkPalindrome(string &s, int i, int j){
       if(i >= j) return true;
        if(memo[i][j] != -1) return memo[i][j];

       if(s[i] == s[j]){
        return memo[i][j] = checkPalindrome(s, i + 1, j - 1);
       }
       return memo[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        memset(memo, -1, sizeof(memo));
        int start = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(checkPalindrome(s, i, j)){
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};