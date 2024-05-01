class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        size_t found = word.find(ch);

        if(found != string::npos){
            reverse(word.begin(), word.begin() + found + 1);
        }
        else{
            return word;
        }

        return word;
    }
};