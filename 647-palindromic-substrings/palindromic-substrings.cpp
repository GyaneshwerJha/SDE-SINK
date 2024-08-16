class Solution {
public:
    bool check(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        // brute force
        int len = s.length();
        int count = 0;
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                // cout<<s.substr(i, j)<<endl;
                if(check(i, j, s)){
                    // cout<<s.substr(i, j);
                    count++;
                }
            }
        }

        return count;
    }
};