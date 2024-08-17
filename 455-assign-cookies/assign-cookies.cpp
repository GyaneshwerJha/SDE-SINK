class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gSize = g.size();
        int sSize = s.size();

        if(sSize == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;
        int j = 0;
        int i = 0;

        while(i < gSize && j < sSize){
            if(g[i] <= s[j]){
                cnt++;
                i++;
            }
            j++;
        }

        return cnt;
    }
};