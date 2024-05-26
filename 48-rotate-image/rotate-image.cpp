#include <algorithm> // For std::reverse

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        // transpose
        for(int row = 0; row < rowSize; row++){
            for(int col = 0; col < row; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        for(int i = 0; i < rowSize; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};