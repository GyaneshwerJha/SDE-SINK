class Solution {
public:
    int m, n;
    void makeItZero(int row, int col, vector<vector<int>> &matrix){
        for(int i = 0; i < m; i++){
            matrix[row][i] = 0;
        }

        for(int i = 0; i < n; i++){
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        n = matrix.size();
        m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    v.push_back({i, j});
                }
            }
        }


        for(int i = 0; i < v.size(); i++){
            auto it = v[i];
            int row = it.first;
            int col = it.second;
            makeItZero(row, col, matrix);
        }

    }
};