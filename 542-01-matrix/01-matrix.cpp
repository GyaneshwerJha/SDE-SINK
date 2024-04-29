class Solution {
public:
    int n = -1, m = -1;

    bool check(int nrow, int ncol){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> ans(mat.begin(), mat.end());
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int dis = it.second;
            q.pop();

            ans[row][col] = dis;

            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, 1, -1};

            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(check(nrow, ncol) && !visited[nrow][ncol] && mat[nrow][ncol] == 1){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dis + 1});
                }
            }
        }
        return ans;
    }
};