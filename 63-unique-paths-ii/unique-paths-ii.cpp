class Solution {
public:

    int solve(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &memo){

        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1){
            return 0;
        }

        if(m == 0 && n == 0 && obstacleGrid[m][n] != 1){
            return 1;
        }

        if(memo[m][n] != -1) return memo[m][n];
        int top = solve(m - 1, n, obstacleGrid, memo);
        int left = solve(m, n - 1, obstacleGrid, memo);
        return memo[m][n] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, obstacleGrid, memo);
    }
};