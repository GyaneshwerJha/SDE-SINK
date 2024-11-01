class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int cnt = 1;
        string ans = "";
        ans.push_back(s[0]);
        for(int i = 1; i < n; i++){
            if(ans.back() == s[i]){
                cnt++;
                if(cnt < 3) ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }

        }
        return ans;
    }
};