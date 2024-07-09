class Solution {
public:
    int memo[101];
    int findCnt(int ind, int n, string s){
        if(ind == n){
            return memo[ind] = 1;
        }

        if(s[ind] == '0'){
            return memo[ind] = 0;
        }
        
        if(memo[ind] != -1) return memo[ind];

        int from1 = findCnt(ind + 1, n, s);

        int from2 = 0;
        if(ind + 1 < n && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))){
            from2 = findCnt(ind + 2, n, s);
        }
        
        return memo[ind] = from1 + from2;
    }

    int numDecodings(string s) {
        int n = s.size();
        int ind = 0;
        for(int i = 0; i < 101; i++){
            memo[i] = -1;
        }
        return findCnt(ind, n, s);
    }
};