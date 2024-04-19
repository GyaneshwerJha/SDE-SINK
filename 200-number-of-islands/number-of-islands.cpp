class Solution {
public:
    bool check(int crow, int ccol, int m, int n){
        return crow >= 0 && crow < m && ccol >= 0 && ccol < n;
    }

    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int nrow[] = {-1, 1, 0, 0};
            int ncol[] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++){
                int crow = row + nrow[k];
                int ccol = col + ncol[k];

                if(check(crow, ccol, m, n) && !vis[crow][ccol] && grid[crow][ccol] == '1'){
                    q.push({crow, ccol});
                    vis[crow][ccol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};