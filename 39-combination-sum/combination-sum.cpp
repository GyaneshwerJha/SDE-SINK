class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int> &temp, int sum, int index, int n, vector<int> &candidates, int target){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        
        if(sum > target || index == n) return;

        // take 
        if(sum <= target){
            temp.push_back(candidates[index]);
            combination(temp, sum + candidates[index], index, n, candidates, target);
            temp.pop_back();
        }
        // not take
        combination(temp, sum, index + 1, n, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int sum = 0;
        int index = 0;
        int n = candidates.size();
        combination(temp, sum, index, n, candidates, target);
        return ans;
    }
};