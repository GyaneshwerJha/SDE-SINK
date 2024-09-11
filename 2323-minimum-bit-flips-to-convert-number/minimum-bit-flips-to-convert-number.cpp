#include <bitset>
class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<64> s1(start);
        bitset<64> s2(goal);

        string c1 = s1.to_string();
        string c2 = s2.to_string();

        int cnt = 0;
        for(int i = 0; i < 64; i++){
            if(c1[i] != c2[i]) cnt++;
        }

        // cout<<c1<< " " << c2;

        return cnt;
    }
};