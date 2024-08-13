class Solution {
public:
        vector<vector<int>> ans;

    void solve(int ind, int n, vector<int> &temp, vector<int> &candidates, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(ind == n || target < candidates[ind]) return;

        
        if(target >= candidates[ind]){
            temp.push_back(candidates[ind]);
            solve(ind + 1, n, temp, candidates, target - candidates[ind]);
            temp.pop_back();
        }

        while(ind + 1 < n && candidates[ind] == candidates[ind + 1]){
            ind++;
        }

        solve(ind + 1, n, temp, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        int ind = 0;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(ind, n, temp, candidates, target);
        return ans;
    }
};