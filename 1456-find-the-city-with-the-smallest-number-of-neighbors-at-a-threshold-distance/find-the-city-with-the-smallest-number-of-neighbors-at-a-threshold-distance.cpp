class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int len = edges.size();

        vector<vector<int>> grid(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++){
            grid[i][i] = 0;
        }

        for(int i = 0; i < len; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];

            grid[from][to] = weight;
            grid[to][from] = weight;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }


        int city = -1;
        int minCount = INT_MAX;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(i != j && grid[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= minCount){
                minCount = count;
                city = i;
            }
        }

        return city;
    }
};