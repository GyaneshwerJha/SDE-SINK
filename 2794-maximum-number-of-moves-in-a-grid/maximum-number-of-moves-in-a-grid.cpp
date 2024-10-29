class Solution {
public:
    int dp[1001][10001];
    int find_maxMove(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if (i >= n || j >= m || i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = 0, up = 0, down = 0;        
        if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] > grid[i][j]) {
            up = 1 + find_maxMove(i - 1, j + 1, n, m, grid);
        }
        if (j + 1 < m && grid[i][j + 1] > grid[i][j]) {
            right = 1 + find_maxMove(i, j + 1, n, m, grid);
        }
        if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] > grid[i][j]) {
            down = 1 + find_maxMove(i + 1, j + 1, n, m, grid);
        }

        int maxi = max({up, down, right});
        return dp[i][j] = maxi;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int result = 0;
        for(int j = 0; j < n; j++){
            result = max(result, find_maxMove(j, 0, n, m, grid));
        }
        return result;
    }
};
