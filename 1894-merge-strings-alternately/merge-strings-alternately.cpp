class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        bool flag = true;
        while(i < n && j < m){
            if(flag){
                ans += word1[i];
                flag = !flag;
                i++;
            }
            else{
                ans += word2[j];
                flag = !flag;
                j++;
            }
        }

        while(i < n){
            ans += word1[i];
            i++;
        }

        while(j < m){
            ans += word2[j];
            j++;
        }

        return ans;
    }
};