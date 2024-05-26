class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1) return ans;
        ans.push_back({1, 1});
        if(numRows == 2) return ans;

        int operation = numRows - ans.size();
        for(int i = 0; i < operation; i++){
            vector<int> temp;
            vector<int> last = ans.back();
            temp.push_back(last[0]);
            for(int i = 0; i < last.size() - 1; i++){
                temp.push_back(last[i] + last[i + 1]);
            }
            temp.push_back(last[last.size() - 1]);
            ans.push_back(temp);
        }
        return ans;
    }
};