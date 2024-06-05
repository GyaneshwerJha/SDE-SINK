class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &temp, int n, int freq[]){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, temp, n, freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int freq[n];
        for(int i = 0; i < n; i++){
            freq[i] = 0;
        }
        solve(nums, temp, n, freq);
        return ans;
    }
};