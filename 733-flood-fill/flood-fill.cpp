class Solution {
public:
    bool isValid(int n, int m, int nrow, int ncol){
        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int newColor = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();
            
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};        

            for(int k = 0; k < 4; k++){
                int nrow = row + dx[k];
                int ncol = col + dy[k];

                if(isValid(n, m, nrow, ncol) && !visited[nrow][ncol] && image[nrow][ncol] == newColor){
                    image[nrow][ncol] = color;
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};