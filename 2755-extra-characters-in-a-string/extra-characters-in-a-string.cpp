class Solution {
public:
    int t[51];
    int solve(int ind, int n, string s, unordered_set<string> &st){
        if(ind >= n) return 0;

        if(t[ind] != -1) return t[ind];

        // assume extra
        int result = 1 + solve(ind + 1, n, s, st);

        // not assume extra
        for(int j = ind; j < n; j++){
            string curr = s.substr(ind, j - ind + 1);
            if(st.count(curr)){
                result = min(result, solve(j + 1, n, s, st));
            }
        }

        return t[ind] = result;
    }


    int minExtraChar(string s, vector<string>& d) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        unordered_set<string> st(d.begin(), d.end());
        return solve(0, n, s, st);
        
    }
};