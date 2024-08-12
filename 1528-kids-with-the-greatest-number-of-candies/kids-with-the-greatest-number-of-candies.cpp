class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n, 0);
        int maxi = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < n; i++){
            if(candies[i] + extraCandies >= maxi){
                ans[i] = 1;
            }
        }

        return ans;
    }
};