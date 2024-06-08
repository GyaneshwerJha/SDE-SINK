class Solution {
public:
    vector<int> v1 = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> v2 = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string intToRoman(int num) {
        string s = "";
        for(int i = 0; i < 13; i++){
            if(num == 0) break;
            if(num >= v1[i]){
                int times = num / v1[i];
                for(int j = 0; j < times; j++){
                    s += v2[i];
                }
                num = num % v1[i];
            }
        }

        return s;
    }
};