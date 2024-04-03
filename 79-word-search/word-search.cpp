class Solution {
public:
   bool solve(int i, int j, int m, int n, int ind, int di[], int dj[], vector<vector<char>> &board, string word){
    if (ind == word.length()) {
        return true;
    }

    for (int k = 0; k < 4; k++) {
        int nexti = i + di[k];
        int nextj = j + dj[k];
        if (nexti >= 0 && nextj >= 0 && nexti < m && nextj < n && board[nexti][nextj] == word[ind]) {
            char c = board[nexti][nextj];
            board[nexti][nextj] = '!';  // Mark the cell as visited
            if (solve(nexti, nextj, m, n, ind + 1, di, dj, board, word)) {
                return true;
            }
            board[nexti][nextj] = c;  // Reset the cell back to its original value
        }
    }

    return false;
}


    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 1){
            if(board[0][0] == word[0]) return true;
        }
        int m = board.size();
        int n = board[0].size();
        int ind = 0;
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(solve(i, j, m, n, ind, di, dj, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};