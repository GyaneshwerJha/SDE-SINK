class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int>upper(150, -1);
        vector<int>lower(150, -1);

        for(int i = 0; i < n; i++){
            // store first occurence of capital letter
            if(word[i] >= 65 && word[i] <= 90){
                if(upper[word[i]] == -1){
                    upper[word[i]] = i;
                }
            }
            else{
                lower[word[i]] = i;
            }
        }

        int count = 0;
        for(int i = 0; i < upper.size(); i++){
            if(upper[i] == -1 || lower[i + 32] == -1) continue;
            else if(lower[i + 32] < upper[i]) count++; 
        }

        return count;
    }
};