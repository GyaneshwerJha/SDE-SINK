class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m){
        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m);
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1, 0, 1};
        int dy[] = {1, 1, 1};
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Initialize the queue with all cells in the first column
        for(int i = 0; i < n; i++) {
            q.push({i, 0});
        }

        // Perform BFS
        while(!q.empty()) {
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();

            for(int k = 0; k < 3; k++) {
                int nrow = row + dx[k];
                int ncol = col + dy[k];

                if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] > grid[row][col] && dist[nrow][ncol] < dist[row][col] + 1) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        // Find the maximum distance
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxi = max(maxi, dist[i][j]);
            }
        }

        return maxi;
    }
};
