class Solution {
public:
 bool isMagical(int row, int col, vector<vector<int>> &grid) {
        vector<int> count(10, 0);  // To check if all numbers from 1 to 9 are distinct
        
        int fSum = 0, sSum = 0, tSum = 0;
        int fCol = 0, sCol = 0, tCol = 0;
        int d1Sum = 0, d2Sum = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                
                if (num < 1 || num > 9) return false;
                
                if (count[num] > 0) return false;
                count[num]++;
                
                if (i == 0) fSum += num;
                else if (i == 1) sSum += num;
                else if (i == 2) tSum += num;
                
                if (j == 0) fCol += num;
                else if (j == 1) sCol += num;
                else if (j == 2) tCol += num;
                
                if (i == j) d1Sum += num;
                if (i + j == 2) d2Sum += num;
            }
        }

        return fSum == sSum && sSum == tSum && fSum == fCol && fCol == sCol && sCol == tCol && fSum == d1Sum && d1Sum == d2Sum;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagical(i, j, grid)) {
                    count++;
                }
            }
        }

        return count;
    }
};