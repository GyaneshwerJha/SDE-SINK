class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxEle = -1;
        int maxIndex = 0;
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }

                    if(dp[i] > maxEle){
                        maxEle = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        cout<<maxIndex<<endl;
        for(int i = 0; i < n; i++){
            cout<<prev[i]<<" ";
        }

        vector<int> ans;
        while(maxIndex >= 0){
            ans.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        return ans;
    }
};