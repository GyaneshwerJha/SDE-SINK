class Solution {
public:
    string findPrefix(string s1, string s2){
        int len1 = s1.size();
        int len2 = s2.size();
        int n = min(len1, len2);
        string ans = "";
        
        int i = 0;
        while(i < n){
            if(s1[i] == s2[i]){
                ans += s1[i];
            }
            else{
                break;
            }
            i++;
        }

        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];

        string prefix = findPrefix(strs[0], strs[1]);

        for(int i = 2; i < n; i++){
            prefix = findPrefix(prefix, strs[i]);
        }

        return prefix;


    }
};