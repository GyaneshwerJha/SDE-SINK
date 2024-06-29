class Solution {
public:
    int rSize, cSize, minPath;
    bool isValid(int nrow, int ncol){
        return (nrow >= 0 && nrow < rSize && ncol >= 0 && ncol < cSize);
    }                                                                                                                                                                                                                                                                                                                                                                                        

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col){
        visited[row][col] = 1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{row, col}, 1});

        while(!q.empty()){
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            int dist = it.second;
            int dx[] = {-1, -1, -1,  0, 0, 1, 1, 1};
            int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
            q.pop();
            if(r == rSize - 1 && c == cSize - 1){
                minPath = min(minPath, dist);
                return;
            }
            for(int k = 0; k < 8; k++){
                int nrow = r + dx[k];
                int ncol = c + dy[k];

                if(isValid(nrow, ncol) && !visited[nrow][ncol] && grid[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dist + 1});
                }
                  
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        rSize = grid.size();
        cSize = grid[0].size();
        minPath = INT_MAX;

        vector<vector<int>> visited(rSize, vector<int>(cSize, 0));
        if(grid[0][0] != 0){
            return -1;
        }

        bfs(grid, visited, 0, 0);
        return minPath == INT_MAX ? -1 : minPath;
    }
};