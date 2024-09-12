class Solution {
public:
    bool isConsistend(string &a, string &b){
        set<char> s1(a.begin(), a.end());
        
        for(int i = 0; i < b.size(); i++){
            if(s1.find(b[i]) == s1.end()){
                return false;
            }
        }

        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();
        int m = allowed.size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(isConsistend(allowed, words[i])){
                cnt++;
            }
        }

        return cnt;
    }
};