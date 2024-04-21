#include <string>

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int a = num[n - 1] - '0';
        if (a % 2 != 0) return num;

        int i = n - 1;
        while (i >= 0 && (num[i] - '0') % 2 == 0) {
            i--;
        }

        if (i < 0) return ""; 

        return num.substr(0, i + 1); 
    }
};
