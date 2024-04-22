class Solution {
public:
    int maxi = INT_MIN;
    bool checkBoundary(int nrow, int ncol, int n, int m){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }
    int one = 0;
    void bfs(vector<vector<int>> &visited, queue<pair<pair<int,int>, int>> &q, vector<vector<int>> &grid){   
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            maxi = max(maxi, time);

            // traverse the negihbour
            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};
            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(checkBoundary(nrow, ncol, n, m) && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = 2;
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol},time + 1});
                    one--;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                if(grid[i][j] == 1){
                    one++;
                }
            }
        } 

        bfs(visited, q, grid);
        if(one != 0){
            return -1;
        }

        return maxi == INT_MIN ? 0 : maxi;
        
    }
};