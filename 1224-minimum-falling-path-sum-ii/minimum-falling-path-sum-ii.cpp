class Solution {
public:
    int n = -1, m = -1;
    int minSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &memo){
        if(i == 0) return grid[i][j]; 
        if(memo[i][j] != -1) return memo[i][j];

        int result = INT_MAX;
        for(int nextJ = 0; nextJ < m; nextJ++){
            if(nextJ != j){
                result = min(result, grid[i][j] + minSum(i - 1, nextJ, grid, memo));
            }
        }

        return memo[i][j] = result;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> memo(n, vector<int>(m, -1));

        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            mini = min(mini, minSum(n - 1, j, grid, memo));
        }

        return mini;
    }
};