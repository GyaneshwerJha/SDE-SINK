class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        
        // for(auto it : mp){
        //     cout<<it.first<< " : "<<it.second<<endl;
        // }
        
        int minLength = 0;
        
        for(auto it : mp){
            int cnt = it.second;
            if(cnt % 2 == 0){
                minLength += 2;
            }
            else{
                minLength += 1;
            }
        }
     
        return minLength;
    }
};