class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int size = original.size();
        if(m * n < size || m * n > size) return {};
        for(int i = 0; i < size - n + 1; i += n){
            vector<int> temp;
            for(int j = i; j < i + n; j++){
                temp.push_back(original[j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};