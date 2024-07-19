class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> minRow(n, vector<int>(m));
        vector<vector<int>> maxCol(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            int mini = *min_element(matrix[i].begin(), matrix[i].end());
            cout<<mini;
            for(int j = 0; j < m; j++){
                minRow[i][j] = mini;
            }
        }

        for (int j = 0; j < m; j++) {
            int maxInColumn = INT_MIN;
            for (int i = 0; i < n; i++) {
                maxInColumn = max(maxInColumn, matrix[i][j]);
            }
            for(int i = 0; i < n; i++){
                maxCol[i][j] = maxInColumn;
            }
        }

        // cout<<"Min Rows : "<<endl;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<minRow[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        // cout<<"Max Col : "<<endl;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout<<maxCol[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }




        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(minRow[i][j] == maxCol[i][j]){
                    ans.push_back(minRow[i][j]);
                }
            }
        }
            
        return ans;

        // return {34};
    }
};