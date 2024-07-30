class Solution {
public:
    // vector<vector<int>> memo;
    int memo[100001][3];
    int solve(int ind, int prev, int n, string &s){
        if(ind > n) return 0;

        if(memo[ind][prev] != -1) return memo[ind][prev];

        // take
        int take = 0;
        if(prev == 0 || s[ind] == 'a' && prev != 2 || s[ind] == 'b'){
            int newPrev = prev;
            if(s[ind] == 'a'){
                newPrev = 1;
            }
            else if(s[ind] == 'b'){
                newPrev = 2;
            }
            take = 1 + solve(ind + 1, newPrev, n, s);
        }

        // not take
        int notTake= solve(ind + 1, prev, n, s);
        return memo[ind][prev] = max(take, notTake);
    }

    int minimumDeletions(string s) {
        int n = s.size();
        memset(memo, -1, sizeof(memo));
        int result = solve(0, 0, n, s);
        return n - result;
    }
};