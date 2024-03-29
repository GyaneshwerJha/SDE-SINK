class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        int maxEle = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;
            while(i <= j && mp[maxEle] >= k){
                mp[nums[i]]--;
                i++;
                count += n - j;
            }
            j++;
        }
        return count;
    }
};