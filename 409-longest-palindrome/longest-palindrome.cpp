class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_set<int> st;
        int res = 0;

        for(auto &ch: s){
            if(st.count(ch)){
                res += 2;
                st.erase(ch);
            }
            else{
                st.insert(ch);
            }
        }

        if(!st.empty()){
            res += 1;
        }

        return res;

    }
};