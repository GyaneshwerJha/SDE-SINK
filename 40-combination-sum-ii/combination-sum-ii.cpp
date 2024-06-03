class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int> &temp, int sum, int index, int n, vector<int> &candidates, int target){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        if(index == n || sum > target) return;

        // take 
        temp.push_back(candidates[index]);
        combination(temp, sum + candidates[index], index + 1, n, candidates, target);
        temp.pop_back();

        while(index + 1 < n && candidates[index] == candidates[index + 1]){
            index++;
        }

        // not take
        combination(temp, sum, index + 1, n, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        int index = 0;
        int sum = 0;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combination(temp, sum, index, n, candidates, target);
        return ans;
    }
};