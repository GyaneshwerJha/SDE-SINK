class Solution {
public:
    int V;
    int X;
    bool isValid(int nrow, int ncol){
        return (nrow >= 0 && nrow < V && ncol >= 0 && ncol < X);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        V = grid.size();
        X = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(V, vector<int>(X, 0));
        int numOne = 0;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < grid[i].size(); j++){
                cout<<grid[i][j]<<endl;
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j] == 1){
                    numOne++;
                }
            
            }
        }
        int minTime = 0;
        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;
            minTime = max(minTime, time);
            q.pop();

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++){
                int nrow = row + dx[k];
                int ncol = col + dy[k];

                if(isValid(nrow, ncol) && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = true;
                    numOne--;
                    q.push({{nrow, ncol}, time + 1});
                }

            }
        }
        // cout<<numOne;
        if(numOne > 0) return -1;
        return minTime;
    }
};