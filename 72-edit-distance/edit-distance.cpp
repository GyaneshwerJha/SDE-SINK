class Solution {
public:

    int minDis(string word1, string word2, int i, int j, vector<vector<int>> &memo){
        if(i <= 0){
            return j;
        }

        if(j <= 0){
            return i;
        }

        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i - 1] == word2[j - 1]){
            return memo[i][j] = 0 + minDis(word1, word2, i - 1, j - 1, memo);
        }
        else{
            int ins =  1 + minDis(word1, word2, i, j - 1, memo);
            int del =  1 + minDis(word1, word2, i - 1, j, memo);
            int rep = 1 + minDis(word1, word2, i - 1, j - 1, memo);
            return memo[i][j] = min(ins, min(del, rep));
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return minDis(word1, word2, m, n, memo);
    }
};