class Solution {
public:
    int r_size;
    int c_size;
    bool isValid(int nrow, int ncol){
        return (nrow >= 0 && nrow < r_size && ncol >= 0 && ncol < c_size);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        r_size = heights.size();
        c_size = heights[0].size();

        vector<vector<int>> grid(r_size, vector<int>(c_size, INT_MAX));
        grid[0][0] = 0;
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            int row = it.second.first;
            int col = it.second.second;
            int prevDiff = it.first;
            pq.pop();

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++){
                int nrow = row + dx[k];
                int ncol = col + dy[k];

                if(isValid(nrow, ncol)){
                    int diff = abs(heights[row][col] - heights[nrow][ncol]);
                    int maxDiff = max(diff, prevDiff);
                    if(grid[nrow][ncol] > maxDiff){
                        grid[nrow][ncol] = maxDiff;
                        pq.push({maxDiff, {nrow, ncol}});
                    }
                     
                }
            }
        }

        return grid[r_size - 1][c_size - 1];
    }
};