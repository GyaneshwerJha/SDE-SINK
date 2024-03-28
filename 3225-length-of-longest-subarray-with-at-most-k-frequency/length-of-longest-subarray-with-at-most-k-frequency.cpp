class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0, j = 0;
        int maxLen = 0;
        while(j < n){
            mp[nums[j]]++;
            // cout<<nums[j] << "->"<< mp[nums[j]] << endl;
                // cout<<nums[j] << " " << endl;
            while(i <= j && mp[nums[j]] > k){
                // cout<<i<<" "<<j<<endl;
                mp[nums[i]]--;
                i++;
            }
            // cout<<j << " " << i << endl; 
            maxLen = max(maxLen, j - i + 1);
            // cout<<maxLen<<" ";
            j++;
        }

        return maxLen;
    }
};