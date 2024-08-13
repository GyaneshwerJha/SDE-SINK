class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        int sum = 0;
        while(k > 0){
            cout<<maxi<<" ";
            sum += maxi;
            maxi++;
            k--;
        }

        return sum;
    }
};