class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                else{
                    if((j - 1 >= 0 && grid[i][j - 1] == 0) || j == 0){
                        perimeter++;
                    }
                    if((j + 1 <= n - 1 && grid[i][j + 1]) == 0 || j == n - 1){
                        perimeter++;
                    }
                    if((i - 1 >= 0 && grid[i - 1][j] == 0) || i == 0){
                        perimeter++;
                    }
                    if((i + 1 <= m - 1 && grid[i + 1][j] == 0) || i == m - 1){
                        perimeter++;
                    }
                }
            }
        }

        return perimeter;
    }
};