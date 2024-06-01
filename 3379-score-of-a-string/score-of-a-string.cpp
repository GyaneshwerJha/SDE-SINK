class Solution {
public:
    int diffAscii(char a, char b){
        return abs(a - b);
    }
    int scoreOfString(string s) {
        int n = s.length();
        int sum = 0;
        sum += diffAscii(s[0], s[1]);
        for(int i = 1; i < n - 1; i++){
            sum += diffAscii(s[i], s[i - 1]);
            sum += diffAscii(s[i], s[i + 1]);
        }
        sum += diffAscii(s[n - 1], s[n - 2]);
        return sum / 2;
    }
};